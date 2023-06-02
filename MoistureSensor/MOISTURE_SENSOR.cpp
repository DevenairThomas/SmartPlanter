#include "MOISTURE_SENSOR.h"

MoistureSensor::MoistureSensor(PinName inputPin):
AnalogMoisturePin(inputPin)
{}
void MoistureSensor::updateSensorData(){
    moistureLevel = AnalogMoisturePin.read()*100;
}
float MoistureSensor::getMoistureData(){
    float retVal;
    mutexMoistureSensor.lock();
    retVal = moistureLevel;
    mutexMoistureSensor.unlock();
    return retVal;
}