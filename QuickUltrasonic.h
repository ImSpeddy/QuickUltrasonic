#ifndef QuickUltrasonic
#define QuickUltrasonic
#include "Arduino.h"

class Ultrasonic {
    public:
        Ultrasonic(uint8_t triggerPin, uint8_t echoPin, bool inCm = true, uint16_t delayTime = 50);
        float getDistance(uint16_t delayTime = DelayTime, bool inCm = InCm);
        void setDelay(uint16_t delayTime);
        void setMeasurement(bool inCm);
    private:
        uint8_t TriggerPin;
        uint8_t EchoPin;
        bool InCm;
        uint16_t DelayTime;
}