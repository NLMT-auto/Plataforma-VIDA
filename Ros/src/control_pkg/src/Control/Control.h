#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string.h>

#include "rclcpp/rclcpp.hpp"
#include "vida_interfaces/msg/controls.hpp"

#include <wiringPi.h>

#include "../../../../../Threads/src/Utils/Serial/Serial.h"


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