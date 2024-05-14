#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <string>

using namespace std;

class Serial
{    
private:

    int serialport; 
    int baudRate; 
    int interrupt;  
    
public: 

    Serial(int interrupt, int baudRate);
    ~Serial();
    
    void write(string s);
    string read(char c);
};

#endif