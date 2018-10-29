
cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
project(LogProfile)
include(CTest)

set (PROJECT_SOURCE_DIR src)

set(engine_source ${PROJECT_SOURCE_DIR}/qt_vs_spdlog_vs_g3log.cpp)

add_executable(LogProfile ${engine_source})

target_include_directories(LogProfile PRIVATE ${PROJECT_SOURCE_DIR}/include ${QTCORE_ROOT}/include ${G3LOG_INCLUDE_DIR} ${G3LOG_GENERATED_HEADER} )

target_link_libraries(LogProfile ${QTCORE_ROOT}/lib/Qt5Core.lib ${G3LOG_LIB} )

