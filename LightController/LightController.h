#ifndef LIGHT_CONTROLLER_H
#define LIGHT_CONTROLLER_H

#include "mbed.h"
#define PWM_PERIOD 100    //placeholder in milliseconds
#define PWM_PULSEWIDTH 100   //placeholder in milliseconds

//TODO
/*
Create thread that will output PWM
Testing to see if PWM Output will output
without a threaded loop
*/
class LightController
{
    private:
    PwmOut RED_CHANNEL, BLU_CHANNEL, WHT_CHANNEL;
    float RED_CHANNEL_VALUE, BLU_CHANNEL_VALUE, WHT_CHANNEL_VALUE;
    Mutex mutexGetRedValue, mutexGetBluValue, mutexGetWhtValue;
    Mutex mutexSetRedValue, mutexSetBluValue, mutexSetWhtValue;
    protected:
    public:
    LightController(PinName redChannel, PinName blueChannel, PinName whiteChannel);
    void initPwmOutputs();

    void OUTPUT_PWM();

    void setChannels(float redChannel, float bluChannel, float whtChannel);
    void setRedChannel(float redChannel);
    void setBluChannel(float bluChannel);
    void setWhtChannel(float whtChannel);

    float getRedChannel();
    float getBluChannel();
    float getWhtChannel();
};
#endif