#include "Serial.h"

int Serial::serialport = -1;
int Serial::tx = 0;
int Serial::rx = 0;
int Serial::baudRate = -1;



Serial::Serial(int tx, int rx, int interrupt, int baudRate)
{
    if (this->serialport < 0)
    {
        this->serialport = serialOpen("/dev/ttyS0", baudRate);
        this->baudRate = baudRate;
        this->tx = tx;
        this->rx = rx;

        wiringPiSetup();
    }

    this->interrupt = interrupt;    
}

Serial::~Serial(){
    serialClose(serialport);
}

void Serial::envia(string s){


    serialPrintf(serialport, "%d %s\n",interrupt, s.c_str());    
}

/*string Serial::leitura(char c){

    string receivedData;
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

    return receivedData;
}*/

