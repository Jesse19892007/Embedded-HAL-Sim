#ifndef SENSORLIB_H
#define SENSORLIB_H

#include <iostream>

enum class TempUnit { C, F, K };

std::ostream &operator<<(std::ostream &os, const TempUnit &unit);

// Base class for all sensors that allows the read value to be of any type.
template <typename T> class Sensor {
public:
  virtual ~Sensor() = default;
  virtual T read() = 0;
};

// An analog sensor provides a continuous, analog output such as a basic photosensor. In this
// project, it is fed into one of the microcontroller's analog inputs. Also establish the read value
// type as float.
class AnalogSensor : public Sensor<float> {
public:
  virtual void init() = 0;  // Set up microcontroller registers for I/O pins.
  virtual float read() = 0; // Read voltage from sensor and convert to temperature (if needed).
};

class AnalogTempSensor : public AnalogSensor {
public:
  virtual void init() = 0;
  virtual float read() = 0; // Default to Celsius.
  virtual float read(TempUnit unit) = 0;
};

// Not implemented. See simulation.
class SpecificAnalogTempSensor1 : public AnalogTempSensor {
public:
  void init() override;
  float read() override;
  float read(TempUnit unit) override;
};

// A base class for digital sensors that provide readings over a communication protocol such as I2C
// or SPI.
class DigitalSensor {
public:
  virtual void init() = 0; // Set up microcontroller registers for I/O pins.
  virtual int read() = 0;
  virtual void close() = 0;
};

// Not implemented. See simulation. Skipped digital temperature sensor abstraction for brevity.
class SpecificDigitalTempSensor1 : public DigitalSensor {
public:
  void init() override;
  int read() override; // Default to Celsius.
  virtual int read(TempUnit unit);
  void close() override;
};

// Not implemented. See simulation.
class SpecificDigitalPressureSensor1 : public DigitalSensor {
public:
  void init() override;
  int read() override;
  void close() override;
};

#endif // SENSORLIB_H
