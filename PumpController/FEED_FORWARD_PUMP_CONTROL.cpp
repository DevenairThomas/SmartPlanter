#include "FEED_FORWARD_PUMP_CONTROL.h"
#include <chrono>



/*
Things for testing:
Test wether the PWM will still output if the Output is not inside a loop
Test changing PWM value and its effect whie not inside a loop
*/

FEED_FORWARD_PUMP_CONTROL::FEED_FORWARD_PUMP_CONTROL(PinName pwmOut):
PWM_PUMP_CONTROL(pwmOut)
{
    initOutput();
}
void FEED_FORWARD_PUMP_CONTROL::initOutput(){
    PWM_PUMP_CONTROL.period_ms(PUMP_PERIOD);
    PWM_PUMP_CONTROL.pulsewidth_ms(PUMP_PULSEWIDTH);
    PWM_PUMP_CONTROL.write(PWM_VALUE);

}
//Initialize in a different Thread
//Calls a thread event that will grab the Set the PWM value
//Write that value to the Pin 
//Do inside a For loop that will increase the PWM_VALUE 
void FEED_FORWARD_PUMP_CONTROL::STEP_INCREASE(float startVal, float endVal, int steps, chrono::microseconds time){
        float stepIncrease = (endVal - startVal)/steps;
        float stepTime;
        
        if(steps == 0 || stepIncrease == 0){return;}

        STEP_TIMER.start();
        stepIncrease = stepIncrease/steps;
        while ( STEP_TIMER.elapsed_time() < time  ){
            
            stepTime = STEP_TIMER.elapsed_time().count();
            stepTime = stepTime*1e6;
            stepTime = (int)stepTime/steps;
            PWM_VALUE += stepIncrease;
            ThisThread::sleep_for(stepTime);
        }
        PUMP_INCREASE_TIME = stepTime;
        STEP_TIMER.stop();
}
void FEED_FORWARD_PUMP_CONTROL::INITIALIZE_STEP_INCREASE(){

}
void FEED_FORWARD_PUMP_CONTROL::Start(){
    PWM_PUMP_CONTROL.resume();
}
void FEED_FORWARD_PUMP_CONTROL::Stop(){
    PWM_PUMP_CONTROL.suspend();
}
void FEED_FORWARD_PUMP_CONTROL::SET_PWM_PUMP_VALUE(float pwmValue){
    float retVal;
    MUTEX_SET_PUMP_VALUE.lock();
    retVal = pwmValue;
    MUTEX_SET_PUMP_VALUE.unlock();
    PWM_VALUE = pwmValue;
}
float FEED_FORWARD_PUMP_CONTROL::GET_PWM_PUMP_VALUE(){
    float retVal;
    MUTEX_GET_PUMP_VALUE.lock();
    retVal = PWM_VALUE;
    MUTEX_GET_PUMP_VALUE.unlock();
    return retVal;
}