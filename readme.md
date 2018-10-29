# Log Porfiler

Compares spdlog vs g3log vs Qt

## Building Log Profiler

Below is an example Windows build:

```bash
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DQTCORE_INCLUDE_DIRS=C:/Projects/qt5/qtbase/lib/Qt5Core.lib -DG3LOG_INCLUDE_DIR=C:/Projects/3rdParty/g3log/build/Release/g3logger.lib
```