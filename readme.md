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

For Mac OSX:

```bash
cmake -DCMAKE_CXX_COMPILER=clang++  -DCMAKE_BUILD_TYPE=Release -DQTCORE_INCLUDE=/Users/<user>/homebrew/opt/qt/include -DQTCORE_LIB=/Users/<user>/homebrew/opt/qt/lib/QtCore.framework -DG3LOG_GENERATED_HEADER=/Users/<user>/Projects/g3log/build/include -DG3LOG_INCLUDE_DIR=/Users/<user>/Projects/g3log/src -DG3LOG_LIB=/Users/<user>/Projects/g3log/build/libg3logger.dylib .. 
```

### Results for spdlog

```bash
Thread count: 1
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        7|        8|        8|       25|       36|       89| 7.553530|

Thread count: 2
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       12|       27|       27|       59|      103|      383|18.911850|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       12|       27|       28|       58|      103|      377|18.924740|

Thread count: 3
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       34|       35|       36|       91|      155|      904|35.424360|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       34|       35|       36|       91|      156|      867|35.435570|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       34|       35|       36|       92|      163|      894|35.434090|

Thread count: 4
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       45|       46|       49|      129|      222|      911|47.865100|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       45|       46|       49|      129|      225|      974|47.883690|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       45|       46|       49|      129|      220|     1105|47.886960|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       45|       46|       49|      129|      231|      908|47.876270|

```

### Results for g3log

```bash
Thread count: 1
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        5|        8|       11|       23|       38|      131| 5.695400|

Thread count: 2
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       10|       11|       13|       38|       60|      189| 8.647740|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       10|       11|       13|       38|       60|      252| 8.691450|

Thread count: 3
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       15|       16|       17|       39|       58|      195|16.160640|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       15|       16|       17|       39|       59|      192|16.179200|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       15|       16|       17|       39|       58|      152|16.168020|

Thread count: 4
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       19|       20|       21|       40|       59|      161|20.313080|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       19|       20|       21|       40|       58|      149|20.317840|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       19|       20|       21|       40|       58|      151|20.314540|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       19|       20|       21|       40|       58|      153|20.307970|

```

### Results for Qt

```bash
Thread count: 1
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        2|        2|        2|       24|      107| 1.384600|

Thread count: 2
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        7|        8|        8|       29|       59|      295| 5.782430|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        7|        8|        8|       29|       60|      286| 5.781700|

Thread count: 3
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       13|       13|       14|       46|       77|      543|13.769700|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       13|       13|       14|       46|       77|      543|13.770550|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       13|       13|       14|       46|       76|      543|13.762800|

Thread count: 4
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       16|       17|       17|       47|       78|      786|17.169880|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       16|       17|       17|       47|       79|      776|17.174030|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       16|       17|       17|       47|       78|      785|17.172090|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
       16|       17|       17|       47|       79|      786|17.162830|

```