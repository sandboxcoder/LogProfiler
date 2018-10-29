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
        1|        1|        2|        6|       39|     1205| 1.265740|

Thread count: 2
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        2|        4|       21|      130|    41742| 3.618770|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        2|        4|       21|      129|    41750| 3.735570|

Thread count: 3
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        3|       14|       52|      295|     6242| 5.489740|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        3|       14|       52|      288|     6088| 5.669370|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        3|       14|       52|      257|     7427| 5.692570|

Thread count: 4
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        3|       16|       55|      489|     4327| 6.795460|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        3|       16|       51|      568|     2635| 6.899270|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        4|       16|       53|      468|     6812| 6.867810|
spdlog percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        1|        3|       16|       56|      543|     6933| 6.963200|
```

### Results for g3log

```bash
Thread count: 1
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|       16|      136|    22581| 4.859710|

Thread count: 2
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        3|        4|       12|      174|    25775| 4.955530|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        3|        4|       13|      182|    23472| 5.362060|

Thread count: 3
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        6|      212|    33269| 6.251060|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        6|      208|    38186| 6.162810|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        7|      194|    38503| 6.719800|

Thread count: 4
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        6|      215|    28084| 6.303730|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        6|      203|    27950| 6.048330|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        3|        4|        4|        6|      210|    28099| 6.896780|
g3log percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        4|        4|        4|        6|      209|    26351| 6.591660|


```

### Results for Qt

```bash
Thread count: 1
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        2|       46|     2814| 1.873090|

Thread count: 2
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        2|       95|    18704| 3.383840|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        2|      114|     7897| 3.515660|

Thread count: 3
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1029|    14232| 5.069050|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1056|    12673| 5.251790|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1046|    24572| 5.503690|

Thread count: 4
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1392|    16713| 6.311610|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1571|    27933| 6.908550|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        3|     1563|    30116| 7.146760|
qt5 percentile latency numbers in microseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
        2|        2|        2|        2|     1727|    23584| 6.974360|
```