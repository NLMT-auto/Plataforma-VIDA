#include "Serial.h"

Serial::Serial(int interrupt, int baudRate)
{    
    this->serialport = serialOpen("/dev/ttyS0", baudRate);          
    this->interrupt = interrupt;    
}

Serial::~Serial(){
    serialClose(serialport);
}

void Serial::write(string s){

    serialPrintf(serialport, "%s\n",s.c_str());    
}

string Serial::read(char c){

    /*string receivedData;
    char receivedChar;

    do
    {
        receivedChar = 0;
        // Lê cada bit
        for (int j = 0; j < 8; ++j)
        {
            receivedChar |= digitalRead(rx) << j;
            delayMicroseconds(1000000 / baudRate); // Aguarda o tempo de bit
        }

        if (receivedChar != c){
            receivedData += receivedChar;
        }

    }while(receivedChar != c);

    return receivedData;*/
}

