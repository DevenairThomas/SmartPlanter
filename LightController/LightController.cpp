#include "LightController.h"

LightController::LightController(PinName redChannel, PinName blueChannel, PinName whiteChannel):
RED_CHANNEL(redChannel),
BLU_CHANNEL(blueChannel),
WHT_CHANNEL(whiteChannel)
{
    //all PWM Out values on the same Bus will has the same frequency
    initPwmOutputs();
}
void LightController::initPwmOutputs(){
    RED_CHANNEL.period_ms(PWM_PERIOD);
    RED_CHANNEL.pulsewidth_ms(PWM_PULSEWIDTH);
    BLU_CHANNEL.period_ms(PWM_PERIOD);
    BLU_CHANNEL.pulsewidth_ms(PWM_PULSEWIDTH);
    WHT_CHANNEL.period_ms(PWM_PERIOD);
    WHT_CHANNEL.pulsewidth_ms(PWM_PULSEWIDTH);
}
void LightController::OUTPUT_PWM(){
    RED_CHANNEL.write(RED_CHANNEL_VALUE);
    BLU_CHANNEL.write(BLU_CHANNEL_VALUE);
    WHT_CHANNEL.write(WHT_CHANNEL_VALUE);
}
void LightController::setChannels(float redChannel, float bluChannel, float whtChannel){
    setRedChannel(redChannel);
    setBluChannel(bluChannel);
    setWhtChannel(whtChannel);
}
void LightController::setRedChannel(float redChannel){
    float retVal;
    mutexGetRedValue.lock();
    retVal = redChannel;
    mutexSetRedValue.unlock();
    RED_CHANNEL_VALUE = retVal;
}
void LightController::setBluChannel(float bluChannel){
    float retVal;
    mutexGetBluValue.lock();
    retVal = bluChannel;
    mutexSetBluValue.unlock();
    BLU_CHANNEL_VALUE = retVal;
}
void LightController::setWhtChannel(float whtChannel){
    float retVal;
    mutexGetWhtValue.lock();
    retVal = whtChannel;
    mutexSetWhtValue.unlock();
    WHT_CHANNEL_VALUE = retVal;
}

float LightController::getRedChannel(){
    float retVal;
    mutexGetRedValue.lock();
    retVal = RED_CHANNEL_VALUE;
    mutexGetRedValue.unlock();
    return retVal;
}
float LightController::getBluChannel(){
    float retVal;
    mutexGetBluValue.lock();
    retVal = BLU_CHANNEL_VALUE;
    mutexGetBluValue.unlock();
    return retVal;
}
float LightController::getWhtChannel(){
    float retVal;
    mutexGetWhtValue.lock();
    retVal = WHT_CHANNEL_VALUE;
    mutexGetWhtValue.unlock();
    return retVal;
}
