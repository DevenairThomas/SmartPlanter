#ifndef FEED_FORWARD_CONTROLLER_H
#define FEED_FORWARD_CONTROLLER_H

#include <chrono>
#define PUMP_PERIOD 100 //placeholder
#define PUMP_PULSEWIDTH 100 //placeholder

#include "mbed.h"
/*
Feedforward Pump control using PWM
The Pin used for PWM Control will be the positve of the relay
Might need a PID Control Loop for better control
*/

class FeedForwardController
{
    private:
        PwmOut _pwmOutput;
        Timer stepTimer;
        Mutex _mutex;
        int _steps;
        float _startVal,_endVal, onTime;
        chrono::milliseconds _time;
        float pwmVal = 0.0;

    protected:
        void FeedForward();

    public:
        FeedForwardController(PwmOut pwmOut);
        void initOutput();
        void initFeedForward(float startVal,float endVal,int steps, int time);
        void Resume();
        void Pause();
        float getOnTime();
};
#endif