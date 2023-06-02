#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

#include "mbed.h"
#include <string>

class SerialCommunication
{
    private:
    UnbufferedSerial& SerialBuffer;
    string MESSAGE;
    Mutex mutexMessageReturn;
    protected:
    public:
    SerialCommunication(UnbufferedSerial serialCommunication);
    void MessageCapture();

    string getMessage();
};
#endif