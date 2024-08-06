#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <wiringpi2/wiringSerial.h>
#include <string>
#include <chrono>
#include "../Files/DefinePin.h"


using namespace std;

class Serial
{
private:
    int serialport;

public:
    Serial(string port);
    ~Serial();

    void write(string s);
    string read(char c);
};

#endif