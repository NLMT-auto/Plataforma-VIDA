#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include "vida_interfaces/msg/controls.hpp"
#include "vida_interfaces/msg/*"
#include <wiringPi.h>
#include "../../../../../Threads/src/Utils/Serial/Serial.h"
#include "../../../../../Threads/src/Files/DefinePin.h"

using namespace std;
using namespace rclcpp;

class Sensors : public Node
{
private:
    
    int frequencyPublish;
    string dataRecived;

    Serial *sensorSerial;
    TimerBase::SharedPtr timer;
    Publisher<vida_interfaces::msg::SensorData>::SharedPtr publisher;
    
    
    void readSensors();

public:
    Sensors(string name);
    ~Sensors();
};

#endif