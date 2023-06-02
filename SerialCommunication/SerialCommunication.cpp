#include "SerialCommunication.h"

SerialCommunication::SerialCommunication(UnbufferedSerial serialCom):
SerialBuffer(serialCom)
{

}
void SerialCommunication::MessageCapture()
{
    //Todo
    /*
    While !CommandRecieved
    if CommandReceived =>
        input into buffer
        Save buffer to MESSAGE variable
    */
}
string SerialCommunication::getMessage()
{
    string retVal;
    mutexMessageReturn.lock();
    retVal = MESSAGE;
    mutexMessageReturn.unlock();
    return MESSAGE;
}