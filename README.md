# Jesse's Embedded Hardware Abstraction Layer and Simulator

A console-based C++ application that simulates embedded sensors using a hardware abstraction layer (HAL).

## Features

- **Sensor Abstraction**: Base classes for analog and digital sensors with virtual interfaces.
- **Simulation**: Simulated implementations of temperature and pressure sensors.
- **Random Data Generation**: Uses C++ random libraries for realistic sensor readings.
- **Unit Conversion**: Support for temperature units (Celsius, Fahrenheit, Kelvin).

## Prerequisites

- **Compiler**: GCC (via MSYS2 on Windows, or equivalent on other platforms).
- **Build System**: Make.
- **C++ Standard**: C++17 or later.

## Building the Project

The project supports two build configurations: Debug and Release.

### Debug Build
Debug build does not differ from the release build.
```bash
make debug
```

### Release Build
Compiles with optimizations and disables debug output for production use.
```bash
make release
```

### Clean Build
Removes all build artifacts and executables.
```bash
make clean
```

## Running the Application

After building, run the executable:
```bash
./main.exe
```

The application will:
1. Display simulated readings from each of the simulated sensors.

## Project Structure

- `include/`: Header files (`sensorlib.h`, `sensorsimlib.h`, `main.h`).
- `src/`: Source files (`sensorlib.cpp`, `sensorsimlib.cpp`, `main.cpp`).
- `tests/`: Test header files (`sensorsimlibtest.h`).
- `build/`: Build artifacts (created during compilation).
- `Makefile`: Build configuration.
- `.vscode/`: VS Code configuration files for tasks and debugging.

## Key Classes and Concepts

- **Sensor<T> Template**: Base class for all sensors, templated on return type.
- **AnalogSensor**: For continuous analog outputs (e.g., temperature sensors).
- **DigitalSensor**: For digital communication protocols (e.g., I2C, SPI).
- **TempUnit Enum**: Defines temperature units (Celsius, Fahrenheit, Kelvin).
- **RandomNum<T> Template**: Generates random numbers for simulation.
- **Debug Macros**: Conditional compilation using `NDEBUG` to enable/disable debug prints.
- **Smart Pointers**: Used for managing sensor objects safely.

## Version History

- **V1.0**: Initial version.

## License

This project is open-source. Feel free to use and modify as needed.