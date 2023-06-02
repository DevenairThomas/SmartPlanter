#ifndef FEED_FORWARD_PUMP_CONTROL_H
#define FEED_FORWARD_PUMP_CONTROL_H

#define PUMP_PERIOD 100 //placeholder
#define PUMP_PULSEWIDTH 100 //placeholder

#include "mbed.h"
/*
Feedforward Pump control using PWM
The Pin used for PWM Control will be the positve of the relay
Might need a PID Control Loop for better control
*/

class FEED_FORWARD_PUMP_CONTROL
{
    private:
    PwmOut PWM_PUMP_CONTROL;
    Timer STEP_TIMER;
    Mutex MUTEX_GET_PUMP_VALUE, MUTEX_SET_PUMP_VALUE;
    float PUMP_INCREASE_TIME;
    float PWM_VALUE = 0.0;
    protected:
    public:
    FEED_FORWARD_PUMP_CONTROL(PinName pwmOut);

    void initOutput();
    
    //Increase the PWM output to the end value
    //Set startVal as the PUMP's initial PWM Value
    //Subtract the startVal from the endVal, divide into steps
    //Divide time by steps
    //Sleep the divided time for int steps
    //Set new PWM Output as the added value of the steps and the
    void STEP_INCREASE(float startVal, float endVal, int steps, chrono::microseconds time);
    void INITIALIZE_STEP_INCREASE();
    void Start();
    void Stop();

    void SET_PWM_PUMP_VALUE(float pwmValue);
    float GET_PWM_PUMP_VALUE();

};
#endif