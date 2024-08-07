#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "vida_interfaces/msg/controls.hpp"
#include "vida_interfaces/msg/sensor_datas.hpp"
#include <wiringpi2/wiringPi.h>
#include "../../../../../Utils/Serial/Serial.h"
#include "../../../../../Utils/Files/DefinePin.h"

using namespace std;
using namespace rclcpp;

class Sensors : public Node
{
private:
    
    int frequencyPublish;
    string dataRecived;

    Serial *sensorSerial;
    TimerBase::SharedPtr timer;
    Publisher<vida_interfaces::msg::SensorDatas>::SharedPtr publisher;
    
    
    void readSensors();

public:
    Sensors(string name);
    ~Sensors();
};

#endif