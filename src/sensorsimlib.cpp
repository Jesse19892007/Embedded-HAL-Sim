#include "sensorsimlib.h"

#pragma region SimSpecificAnalogTempSensor1
void SimSpecificAnalogTempSensor1::init() {
  // Set up microcontroller I/O pins.
  std::cout << "SimSpecificAnalogTempSensor1 initialized." << std::endl;
}

float SimSpecificAnalogTempSensor1::read() {
  RandomNum<float> rng;
  float tempC = rng.generate(0.0f, 100.0f); // Simulated temp range: 0-100 C
  return tempC;
}

// TODO: Encapsulate and generalize unit conversion.
float SimSpecificAnalogTempSensor1::read(TempUnit unit) {
  float tempC = read(); // Get temperature in Celsius
  float result;
  switch (unit) {
  case TempUnit::C:
    result = tempC;
    break;
  case TempUnit::F:
    result = tempC * 9.0f / 5.0f + 32.0f;
    break;
  case TempUnit::K:
    result = tempC + 273.15f;
    break;
  }
  return result;
}
#pragma endregion

#pragma region SimSpecificDigitalTempSensor1
void SimSpecificDigitalTempSensor1::init() {
  // Set up microcontroller communication.
  std::cout << "SimSpecificDigitalTempSensor1 initialized." << std::endl;
}

// Simulate reading a temperature in Celsius.
int SimSpecificDigitalTempSensor1::read() {
  RandomNum<int> rng;
  int tempC = rng.generate(0, 100); // Simulated temp range: 0-100 C
  return tempC;
}

int SimSpecificDigitalTempSensor1::read(TempUnit unit) {
  int tempC = read(); // Get temperature in Celsius
  int result;

  switch (unit) {
  case TempUnit::C:
    result = tempC;
    break;
  case TempUnit::F:
    result = static_cast<int>(tempC * 9.0 / 5.0 + 32);
    break;
  case TempUnit::K:
    result = tempC + 273;
    break;
  }

  return result;
}

void SimSpecificDigitalTempSensor1::close() {
  // Close communication.
  std::cout << "SimSpecificDigitalTempSensor1 closed." << std::endl;
}
#pragma endregion

#pragma region SimSpecificDigitalPressureSensor1
void SimSpecificDigitalPressureSensor1::init() {
  std::cout << "SimSpecificDigitalPressureSensor1 initialized." << std::endl;
}

int SimSpecificDigitalPressureSensor1::read() {
  RandomNum<int> rng;
  int pressure = rng.generate(950, 1050); // Simulated pressure range: 950-1050 hPa
  return pressure;
}

void SimSpecificDigitalPressureSensor1::close() {
    // Close communication.
  std::cout << "SimSpecificDigitalPressureSensor1 closed." << std::endl;
}
#pragma endregion