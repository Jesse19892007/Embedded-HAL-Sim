#include "main.h"

int main() {
  testSensorSimLib();
  std::cout << "Press Enter to exit..." << std::endl;
  std::cin.get();
  return 0;
}

int testSensorSimLib() {
  std::cout << "Testing Sensor Simulation Library..." << std::endl;
  std::cout << "\n";
  testSimSpecificAnalogTempSensor1();
  std::cout << "\n";
  testSimSpecificDigitalTempSensor1();
  std::cout << "\n";
  testSimSpecificDigitalPressureSensor1();
  std::cout << "\n";
  return 0;
}