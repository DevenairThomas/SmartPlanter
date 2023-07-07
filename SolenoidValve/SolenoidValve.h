#ifndef SOLENOID_VALVE_H
#define SOLENOID_VALVE_H
#include "mbed.h"

class SOLENOID_VALVE{
    private:
    PwmOut VALVE_PIN;
    bool VALVE_OPEN = true;     //boolean starts as true to make sure when the valve is initialized the valve is then closed
    Mutex MUTEX_VALVE_STATE;
    protected:

    //Make sure the valve is closed
    //Set bool valve to Close
    void INIT_VALVE();

    public:
    SOLENOID_VALVE(PinName valvePin);

    void OPEN();
    void CLOSE();

    bool GET_VALVE_STATE();

};
#endif