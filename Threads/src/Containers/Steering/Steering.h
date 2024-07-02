#ifndef STEERING_H
#define STEERING_H

#include <iostream>
#include <sstream>
#include <wiringPi.h>

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/Serial/Serial.h"
#include "../../Files/Struct_sensors.h"
#include "../../Files/DefinePin.h"

using namespace std;

class Steering : public ThreadBase
{
private:
    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem *memoryShared;
    Steering_data steeringData;
    string buffer;
    
    Serial *serialSensors;

public:
    Steering();
    ~Steering();
};

#endif