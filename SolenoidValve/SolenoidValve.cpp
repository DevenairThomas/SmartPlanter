#include "SolenoidValve.h"

SOLENOID_VALVE::SOLENOID_VALVE(PinName valvePin):
VALVE_PIN(valvePin)
{
    INIT_VALVE();
}
void SOLENOID_VALVE::INIT_VALVE(){
    //Solenoid Valve initialize setup per Datasheet
    CLOSE();
}
void SOLENOID_VALVE::OPEN(){
    if(VALVE_OPEN == true){ return; }
    VALVE_PIN.write(1); //Value to write to close the Valve
    //
    //Probably some sort of check to see if the valve is actually open
    //
    //if(check == true){
    VALVE_OPEN = true;
    //}
}
void SOLENOID_VALVE::CLOSE(){
    if(VALVE_OPEN == false){ return; }
    VALVE_PIN.write(0); //Value to write to close the Valve
    //
    //Probably some sort of check to see if the valve is actually open
    //
    //if(check == true){
    VALVE_OPEN = false;
    //}
}
bool SOLENOID_VALVE::GET_VALVE_STATE(){
    bool retVal;
    MUTEX_VALVE_STATE.lock();
    retVal = VALVE_OPEN;
    MUTEX_VALVE_STATE.unlock();
    return retVal;
}