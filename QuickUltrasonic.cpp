#include "Arduino.h"
#include "QuickUltrasonic.h"

Ultrasonic::Ultrasonic(uint8_t triggerPin, uint8_t echoPin, bool inCm, uint16_t delayTime){
    TriggerPin = triggerPin;
    EchoPin = echoPin;
    InCm = inCm;
    DelayTime = delayTime;
    // Initialize the pins
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
}

float Ultrasonic::getDistance(uint16_t delayTime, bool inCm) {
    // Trigger the ultrasonic sensor
    digitalWrite(TriggerPin, LOW);
    delay(delayTime);
    digitalWrite(TriggerPin, LOW);

    // Measure the echo time
    long duration = pulseIn(EchoPin, HIGH);

    // Calculate distance based on the measurement unit
    if (inCm) {
        return duration * 0.034 / 2; // Return distance in cm
    } else {
        return duration; // Return duration
    }
}

void Ultrasonic::setDelay(uint16_t delayTime) {
    DelayTime = delayTime;
}

void Ultrasonic::setMeasurement(bool inCm) {
    InCm = inCm;
}