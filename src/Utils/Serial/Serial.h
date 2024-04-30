#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>

using namespace std;

class Serial
{    
private:

    static int serialport;
    static int tx;
    static int rx;
    static int baudRate;    

    int interrupt;  
    
public: 
    Serial(int tx, int rx, int interrupt, int baudRate);
    ~Serial();
    string leitura(char c);
    void envia(string s);
};

#endif