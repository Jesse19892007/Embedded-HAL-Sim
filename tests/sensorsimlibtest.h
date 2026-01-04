#ifndef SENSORSIMLIBTEST_H
#define SENSORSIMLIBTEST_H

#include "sensorsimlib.h"

void testSimSpecificAnalogTempSensor1() {
  SimSpecificAnalogTempSensor1 sensor = SimSpecificAnalogTempSensor1();
  sensor.init();
  for (int i = 0; i < 10; ++i) {
    float tempC = sensor.read(TempUnit::C);
    float tempF = sensor.read(TempUnit::F);
    float tempK = sensor.read(TempUnit::K);
    std::cout << "Simulated Temperature Readings: " << tempC << " C, " << tempF << " F, " << tempK
              << " K" << std::endl;
  }
}

void testSimSpecificDigitalTempSensor1() {
  SimSpecificDigitalTempSensor1 sensor = SimSpecificDigitalTempSensor1();
  sensor.init();
  for (int i = 0; i < 10; ++i) {
    int tempC = sensor.read(TempUnit::C);
    int tempF = sensor.read(TempUnit::F);
    int tempK = sensor.read(TempUnit::K);
    std::cout << "Simulated Digital Temperature Readings: " << tempC << " C, " << tempF << " F, "
              << tempK << " K" << std::endl;
  }
  sensor.close();
}

void testSimSpecificDigitalPressureSensor1() {
  SimSpecificDigitalPressureSensor1 sensor = SimSpecificDigitalPressureSensor1();
  sensor.init();
  for (int i = 0; i < 10; ++i) {
    int pressure = sensor.read();
    std::cout << "Simulated Digital Pressure Reading: " << pressure << " hPa" << std::endl;
  }
  sensor.close();
}

#endif // SENSORSIMLIBTEST_H