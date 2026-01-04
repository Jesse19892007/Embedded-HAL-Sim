#ifndef SENSORSIMLIB_H
#define SENSORSIMLIB_H

#include "sensorlib.h"
#include <random>

// Random number generator with a flexible output type.
// TODO: Setup as a global resource to avoid reseeding on each call.
template <typename T> class RandomNum {
public:
  RandomNum() : gen(std::random_device{}()) {}

  T generate(T min, T max) {
    if constexpr (std::is_integral_v<T>) {
      std::uniform_int_distribution<T> dis(min, max);
      return dis(gen);
    } else {
      std::uniform_real_distribution<T> dis(min, max);
      return dis(gen);
    }
  }

private:
  std::mt19937 gen;
};

// Simulation of SpecificAnalogTempSensor1.
class SimSpecificAnalogTempSensor1 : public SpecificAnalogTempSensor1 {
public:
  void init() override;
  float read() override;
  float read(TempUnit unit) override;
};

// Simulation of SpecificDigitalTempSensor1.
class SimSpecificDigitalTempSensor1 : public SpecificDigitalTempSensor1 {
public:
  void init() override;
  int read() override;
  int read(TempUnit unit) override;
  void close() override;
};

// Simulation of SpecificDigitalPressureSensor1.
class SimSpecificDigitalPressureSensor1 : public SpecificDigitalPressureSensor1 {
public:
  void init() override;
  int read() override;
  void close() override;
};

#endif // SENSORSIMLIB_H