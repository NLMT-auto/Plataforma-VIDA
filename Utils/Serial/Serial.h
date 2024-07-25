#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <wiringpi2/wiringSerial.h>
#include <string>

#include "../Files/DefinePin.h"
#include "../road_time.h"

using namespace std;

class Serial
{
private:
    int serialport;
    road_time_t time;

public:
    Serial(string port);
    ~Serial();

    void write(string s);
    string read(char c);
};

#endif