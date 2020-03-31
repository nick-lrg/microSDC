# MicroSDC

An SDC IEEE 11073 implementation for microarchitectures.

MicroSDC targets the ESP32 using the official development framework [ESP-IDF](https://github.com/espressif/esp-idf/).

## Essential requirements

- C++17 compiler support ([C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support#cpp17))
- CMake (>= 3.10)

using the reference implementation for ePsp32 targets:

- [ESP-IDF](https://github.com/espressif/esp-idf/) at master with at least [572408351](https://github.com/espressif/esp-idf/commit/582f5dd697fde49eea1f1dfe0c86f9f2f48bb223)

## Setup and build for ESP32

The reference example is found at [examples/esp32/](examples/esp32/).
As [ESP-IDF](https://github.com/espressif/esp-idf/) uses it's own CMake based build chain, MicroSDC is embedded as a single component.

To setup [ESP-IDF](https://github.com/espressif/esp-idf/) follow the installation steps at [Get Started](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).

Furthermore you need to set the c++ standard to c++17.  
This can be achieved by replacing the line

```
list(APPEND cxx_compile_options "-std=gnu++11")
```

with

```
list(APPEND cxx_compile_options "-std=gnu++17")
```

in the file `$IDF_PATH/tools/cmake/build.cmake`.

The MicroSDC project example can be configured with:

```
cd examples/esp32/
idf.py menuconfig
```

Network is configured in `menuconfig --> Network Configuration`.

After setup and configuration the image is built with:

```
idf.py build
```

and flashed via:

```
idf.py flash monitor
```

## Documentation

For further documentation consult the doxygen generated pages as well as the example at [examples/esp32/main/main.cpp](examples/esp32/main/main.cpp).
