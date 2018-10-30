# Log Profiler

Compares spdlog vs g3log vs Qt

Special thanks to Nanolog which is where I got the performance tests: https://github.com/Iyengar111/NanoLog

## Building Log Profiler

Below is an example Windows build:

```bash
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DQTCORE_INCLUDE=C:/Projects/qt5/qtbase/include -DG3LOG_LIB=C:/Projects/3rdParty/g3log/build/Release/g3logger.lib -DQTCORE_LIB=C:/Projects/qt5/qtbase/lib/Qt5Core.lib -DG3LOG_INCLUDE_DIR=C:/Projects/3rdParty/g3log/src -DG3LOG_GENERATED_HEADER=C:/Projects/3rdParty/g3log/build/include ..
(Open Visual Studio and compile)
```

For Mac OSX:

```bash
cmake -G "Unix makefiles" -DCMAKE_BUILD_TYPE=Release -DQTCORE_INCLUDE=/Users/<user>/homebrew/opt/qt/include -DQTCORE_LIB=/Users/<user>/homebrew/opt/qt/lib/QtCore.framework -DG3LOG_GENERATED_HEADER=/Users/<user>/Projects/g3log/build/include -DG3LOG_INCLUDE_DIR=/Users/<user>/Projects/g3log/src -DG3LOG_LIB=/Users/<user>/Projects/g3log/build/libg3logger.dylib .. 
make
```

### Results for spdlog

```bash
Thread count: 1
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000004| 0.000016| 0.001734| 0.000001|

Thread count: 2
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000005| 0.000021| 0.015213| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000006| 0.000026| 0.017451| 0.000002|

Thread count: 3
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000002| 0.000007| 0.000031| 0.029229| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000002| 0.000007| 0.000040| 0.009672| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000006| 0.000034| 0.016927| 0.000002|

Thread count: 4
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000004| 0.000023| 0.027530| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000004| 0.000022| 0.028935| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000006| 0.000042| 0.025007| 0.000002|
spdlog percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000001| 0.000001| 0.000001| 0.000006| 0.000028| 0.026074| 0.000002|
```

### Results for g3log

```bash
Thread count: 1
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000024| 0.000147| 0.010630| 0.000005|

Thread count: 2
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000010| 0.000077| 0.036292| 0.000005|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000013| 0.000074| 0.021295| 0.000005|

Thread count: 3
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000005| 0.000114| 0.043024| 0.000005|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000003| 0.000006| 0.000161| 0.038319| 0.000006|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000006| 0.000186| 0.042481| 0.000006|

Thread count: 4
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000003| 0.000006| 0.000245| 0.036032| 0.000007|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000003| 0.000005| 0.000186| 0.061040| 0.000007|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000003| 0.000006| 0.000212| 0.059584| 0.000007|
g3log percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000003| 0.000003| 0.000004| 0.000006| 0.000194| 0.038523| 0.000006|

```

### Results for Qt

```bash
Thread count: 1
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000010| 0.000170| 0.004970| 0.000003|

Thread count: 2
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000005| 0.000118| 0.009558| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000005| 0.000116| 0.017443| 0.000002|

Thread count: 3
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000015| 0.000148| 0.004095| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000016| 0.000172| 0.012521| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000015| 0.000152| 0.007847| 0.000003|

Thread count: 4
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000019| 0.000143| 0.006238| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000020| 0.000204| 0.004929| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000020| 0.000183| 0.004636| 0.000003|
qt5 percentile latency numbers in nanoseconds
     50th|     75th|     90th|     99th|   99.9th|    Worst|  Average|
 0.000002| 0.000002| 0.000002| 0.000019| 0.000180| 0.005358| 0.000003|

```