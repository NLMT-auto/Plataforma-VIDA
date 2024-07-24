#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include "vida_interfaces/msg/controls.hpp"
#include "vida_interfaces/msg/sensor_datas.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace rclcpp;

using placeholders::_1;

class Record : public Node
{
private:
    
    ofstream outputSensors;
    ostringstream BufferDataRecived;      
    int count = 0;  

    Subscription<vida_interfaces::msg::SensorDatas>::SharedPtr subscriber;
    
    
    void sensorDataCallBack(const vida_interfaces::msg::SensorDatas::SharedPtr msg);
    void saveSensors();

public:
    Record(string name);
    ~Record();
};

#endif