#ifndef MOISURE_SENSOR_H
#define MOISURE_SENSOR_H

#include "mbed.h"

class MoistureSensor
{
    private:
    AnalogIn AnalogMoisturePin;
    float moistureLevel;
    Mutex mutexMoistureSensor;
    protected:
    public:
    MoistureSensor(PinName inputPin);
    void updateSensorData();
    float getMoistureData();
};


#endif