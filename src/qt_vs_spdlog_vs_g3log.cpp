// This code was shamelessly lifted from https://github.com/Iyengar111/NanoLog/blob/master/nano_vs_spdlog_vs_g3log_vs_reckless.cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"
#include <QtCore/QDebug>
#include <QtCore/QMessageLogger>
#include <QtCore/QGlobal.h>
#include <QtCore/QFile.h>
#include <QtCore/QTextStream.h>
#include <mutex>

namespace {
	std::mutex g_qt_debug_mutex;
	std::shared_ptr<QTextStream> g_qt_output;
}

template < typename Function >
void run_log_benchmark(Function && f, char const * const logger)
{
    int iterations = 100000;
    std::vector < double > latencies;
    char const * const benchmark = "benchmark";
    for (int i = 0; i < iterations; ++i)
    {
	auto begin = std::chrono::high_resolution_clock::now();
	f(i, benchmark);
	auto delta = std::chrono::high_resolution_clock::now() - begin;
	auto delta_d = std::chrono::duration_cast<std::chrono::duration<double>>(delta).count();
	latencies.push_back(delta_d);
    }
    std::sort(latencies.begin(), latencies.end());
    double sum = 0; for (auto latency : latencies) { sum += latency; }
    printf("%s percentile latency numbers in nanoseconds\n%9s|%9s|%9s|%9s|%9s|%9s|%9s|\n%9s|%9s|%9s|%9s|%9s|%9s|%9f|\n"
	   , logger
	   , "50th"
	   , "75th"
	   , "90th"
	   , "99th"
	   , "99.9th"
	   , "Worst"
	   , "Average"
	   , std::to_string(latencies[(size_t)iterations * 0.5])
	   , std::to_string(latencies[(size_t)iterations * 0.75])
	   , std::to_string(latencies[(size_t)iterations * 0.9])
	   , std::to_string(latencies[(size_t)iterations * 0.99])
	   , std::to_string(latencies[(size_t)iterations * 0.999])
	   , std::to_string(latencies[latencies.size() - 1])
	   , (sum * 1.0) / latencies.size()
	);
}

template < typename Function >
void run_benchmark(Function && f, int thread_count, char const * const logger)
{
    printf("\nThread count: %d\n", thread_count);
    std::vector < std::thread > threads;
    for (int i = 0; i < thread_count; ++i)
    {
		threads.emplace_back(run_log_benchmark<Function>, std::ref(f), logger);
    }
    for (int i = 0; i < thread_count; ++i)
    {
		threads[i].join();
    }
}

void print_usage()
{
    char const * const executable = "LogProfile";
    printf("Usage \n1. %s qt5\n2. %s spdlog\n3. %s g3log\n", executable, executable, executable, executable);
}

void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg) {
	std::lock_guard<std::mutex> lock(g_qt_debug_mutex);
	(*g_qt_output) << msg;
}

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
		print_usage();
		system("pause");
		return 0;
    }

    if (strcmp(argv[1], "spdlog") == 0)
    {
		spdlog::init_thread_pool(1048576, 1);
		auto spd_logger = spdlog::basic_logger_mt<spdlog::async_factory>("file_logger", "async_log.txt");

		auto spdlog_benchmark = [&spd_logger](int i, char const * const cstr) { spd_logger->info("Logging {}{}{}{}{}", cstr, i, 0, 'K', -42.42); };
		for (auto threads : { 1, 2, 3, 4 })
			run_benchmark(spdlog_benchmark, threads, "spdlog");
    }
    else if (strcmp(argv[1], "g3log") == 0)
    {
		auto worker = g3::LogWorker::createLogWorker();
		auto handle = worker->addDefaultLogger("g3", "tmp");
		g3::initializeLogging(worker.get());

		auto g3log_benchmark = [](int i, char const * const cstr) { LOGF(INFO, "Logging %s%d%d%c%lf", cstr, i, 0, 'K', -42.42); };
		for (auto threads : { 1, 2, 3, 4 })
			run_benchmark(g3log_benchmark, threads, "g3log");
    }
	else if (strcmp(argv[1], "qt5") == 0)
	{
		qInstallMessageHandler(myMessageHandler);
		QFile data("qlog.txt");
		if (data.open(QFile::WriteOnly | QFile::Truncate)) {
			g_qt_output.reset(new QTextStream(&data));
			auto qtlog_benchmark = [](int i, char const * const cstr) {
				QMessageLogger().info("Logging %s%d%d%c%lf", cstr, i, 0, 'K', -42.42);
			};
			for (auto threads : { 1, 2, 3, 4 })
				run_benchmark(qtlog_benchmark, threads, "qt5");
		}
	}
    else
    {
		print_usage();
    }

	system("pause");
    return 0;
}

