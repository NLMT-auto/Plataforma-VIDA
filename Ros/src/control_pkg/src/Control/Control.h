#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string.h>
#include <wiringpi2/wiringPi.h>
#include "rclcpp/rclcpp.hpp"
#include "vida_interfaces/msg/controls.hpp"
#include "../../../../../Threads/src/Utils/Serial/Serial.h"
#include "../../../../../Threads/src/Files/DefinePin.h"

using namespace std;
using namespace rclcpp;

using placeholders::_1;

class Control : public Node
{
private:
    
    Serial *motorSerial;
    Subscription<vida_interfaces::msg::Controls>::SharedPtr subscriber;

    void callbackControls(const vida_interfaces::msg::Controls::SharedPtr msg);
    

public:
    Control(string name);
    ~Control();
};

#endif