# QuickUltrasonic

A simple Arduino library for interfacing with the HC-SR04 Ultrasonic Sensor.

## Overview

**QuickUltrasonic** provides an easy-to-use C++ class for measuring distances using the HC-SR04 ultrasonic sensor. It abstracts away the low-level pin handling and timing, letting you focus on your project.

## Features

- Simple API for distance measurement
- Configurable trigger and echo pins
- Supports measurements in centimeters or raw microseconds
- Adjustable measurement delay

## Hardware Requirements

- HC-SR04 Ultrasonic Sensor

## Usage

### Basic Example

```cpp
#include "QuickUltrasonic.h"

Ultrasonic sensor(9, 10); // Trigger pin 9, Echo pin 10

void setup() {
    Serial.begin(9600);
}

void loop() {
    float distance = sensor.getDistance(); // Default: centimeters
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}
```

### Constructor

```cpp
Ultrasonic(uint8_t triggerPin, uint8_t echoPin, bool inCm = true, uint16_t delayTime = 50);
```
- `triggerPin`: Arduino pin connected to the sensor's trigger
- `echoPin`: Arduino pin connected to the sensor's echo
- `inCm`: `true` for centimeters, `false` for raw microseconds (default: `true`)
- `delayTime`: Delay before measurement in milliseconds (default: `50`)

### Methods

- `float getDistance(uint16_t delayTime = DelayTime, bool inCm = InCm);`  
  Measure distance. Optional parameters override defaults.
- `void setDelay(uint16_t delayTime);`  
  Set the measurement delay.
- `void setMeasurement(bool inCm);`  
  Set measurement unit (`true` for cm, `false` for microseconds).

## License

MIT License

## Author

Ethan Mahlstedt