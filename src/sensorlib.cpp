#include "sensorlib.h"

// Implementation of sensors goes here. None are implemented in this simulation.

std::ostream &operator<<(std::ostream &os, const TempUnit &unit) {
  switch (unit) {
  case TempUnit::C:
    os << "Celsius";
    break;
  case TempUnit::F:
    os << "Fahrenheit";
    break;
  case TempUnit::K:
    os << "Kelvin";
    break;
  }
  return os;
}

#pragma region SpecificAnalogTempSensor1
void SpecificAnalogTempSensor1::init() {
  std::cout << std::endl << "SpecificAnalogTempSensor1 init() called." << std::endl;
}

float SpecificAnalogTempSensor1::read() {
  std::cout << std::endl << "SpecificAnalogTempSensor1 read() called." << std::endl;
  return 0.0f;
}

float SpecificAnalogTempSensor1::read(TempUnit unit) {
  std::cout << std::endl << "SpecificAnalogTempSensor1 read(" << unit << ") called." << std::endl;
  return 0.0f;
}
#pragma endregion

#pragma region SpecificDigitalTempSensor1
void SpecificDigitalTempSensor1::init() {
  std::cout << std::endl << "SpecificDigitalTempSensor1 init() called." << std::endl;
  // Ensure communication pins are configured.
  // Send any initialization commands to the sensor.
}

int SpecificDigitalTempSensor1::read() {
  std::cout << std::endl << "SpecificDigitalTempSensor1 read() called." << std::endl;
  return 42;
}

int SpecificDigitalTempSensor1::read(TempUnit unit) {
  std::cout << std::endl << "SpecificDigitalTempSensor1 read(" << unit << ") called." << std::endl;
  return 42;
};

void SpecificDigitalTempSensor1::close() {
  std::cout << std::endl << "SpecificDigitalTempSensor1 close() called." << std::endl;
  // Send any shutdown commands to the sensor.
}
#pragma endregion

#pragma region SpecificDigitalPressureSensor1
void SpecificDigitalPressureSensor1::init() {
  std::cout << std::endl << "SpecificDigitalPressureSensor1 init() called." << std::endl;
  // Ensure communication pins are configured.
  // Send any initialization commands to the sensor.
}
int SpecificDigitalPressureSensor1::read() {
  std::cout << std::endl << "SpecificDigitalPressureSensor1 read() called." << std::endl;
  return 42;
}

void SpecificDigitalPressureSensor1::close() {
  std::cout << std::endl << "SpecificDigitalPressureSensor1 close() called." << std::endl;
  // Send any shutdown commands to the sensor.
}
#pragma endregion
