# Log Profiler

Compares spdlog vs g3log vs Qt

 Special thanks to Nanolog which is where I got the performance tests: https://github.com/Iyengar111/NanoLog

## Building Log Profiler

Below is an example Windows build:

```bash
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DQTCORE_ROOT=C:/Projects/qt5/qtbase -DG3LOG_LIB=C:/Projects/3rdParty/g3log/build/Release/g3logger.lib -DG3LOG_INCLUDE_DIR=C:/Projects/3rdParty/g3log/src -DG3LOG_GENERATED_HEADER=C:/Projects/3rdParty/g3log/build/include ..
```


### Results for spdlog

```bash
Thread count: 1
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        2|        2|       14|       84|     5402| 2.007680|

Thread count: 2
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        6|       49|      293|    13511| 5.654200|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        6|       51|      295|    22428| 6.007530|

Thread count: 3
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        6|       31|      104|      452|     9354|11.735600|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        7|       31|      106|      430|     9984|11.905410|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        7|       31|      107|      451|    14807|12.142390|

Thread count: 4
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|       21|       39|      113|      574|     5200|14.385980|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|       22|       39|      118|      649|     7221|14.910420|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|       22|       39|      121|      584|     8738|14.843960|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|       22|       40|      126|      598|    10148|14.928000|
```

### Results for g3log

```bash
Thread count: 1
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        5|        5|       31|      174|    31917| 6.895430|

Thread count: 2
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        5|        5|       19|      201|    41167| 7.848010|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        5|        5|       22|      380|    34261| 8.558150|

Thread count: 3
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        5|        5|       10|      267|    24540| 7.862150|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|       11|      276|    36898| 8.575030|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|       10|      277|    31939| 8.202260|

Thread count: 4
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|       10|      304|    30042| 9.006020|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|        9|      287|    35403| 9.059890|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|       10|      285|    40089| 9.738090|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        5|        5|       10|      283|    49931| 9.879920|


```

### Results for Qt

```bash
Thread count: 1
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        7|      255|    61524| 6.613520|

Thread count: 2
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        5|      386|    34532| 5.841270|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        5|      660|    10814| 5.739830|

Thread count: 3
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        3|        3|        4|     1324|    18460| 7.848550|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        4|     1399|    21945| 7.987410|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        3|        3|        4|     1774|    20565| 8.529770|

Thread count: 4
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        5|     3170|    23339|11.585570|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        5|     2909|    25447|11.687090|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|        3|        5|     3424|    25107|12.365340|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        5|        5|        8|     2959|    13982|12.427000|
```