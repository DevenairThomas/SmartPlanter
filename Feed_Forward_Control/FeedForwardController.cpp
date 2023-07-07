#include "FeedForwardController.h"
#include <chrono>

FeedForwardController::FeedForwardController(PwmOut pwmOut):
_pwmOutput(pwmOut)
{
    initOutput();
}
void FeedForwardController::initOutput(){
    _pwmOutput.period_ms(PUMP_PERIOD);
    _pwmOutput.pulsewidth_ms(PUMP_PULSEWIDTH);
}
void FeedForwardController::FeedForward(){
        float stepIncrease = (_endVal - _startVal)/_steps;
        float stepTime;
        
        if(_steps == 0 || stepIncrease == 0){return;}

        stepTimer.start();
        stepIncrease = stepIncrease/_steps;
        while ( stepTimer.elapsed_time() < _time  ){
            
            stepTime = stepTimer.elapsed_time().count();
            stepTime = stepTime*1e6;
            stepTime = (int)stepTime/_steps;
            pwmVal += stepIncrease;
            _pwmOutput.write(pwmVal);
            ThisThread::sleep_for(stepTime);
        }
        onTime = stepTime;
        stepTimer.stop();
}
void FeedForwardController::initFeedForward( float startVal,float endVal,int steps, int time ){
    _mutex.lock();
    _startVal = startVal;
    _endVal = endVal;
    _steps = steps;
    _time =  chrono::milliseconds(time);
    _mutex.unlock();
    Thread thread;
    thread.start(callback(this,&FeedForwardController::FeedForward));
}
void FeedForwardController::Resume(){
    _pwmOutput.resume();
}
void FeedForwardController::Pause(){
    _pwmOutput.suspend();
}
float FeedForwardController::getOnTime(){
    float retVal;
    _mutex.lock();
    retVal = onTime;
    _mutex.unlock();
    return retVal;
}