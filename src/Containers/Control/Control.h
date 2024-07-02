#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <wiringPi.h>

#include "../../Utils/UDP/UDP.h"
#include "../../Utils/Serial/Serial.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Files/DefinePin.h"

using namespace std;

class Control : public ThreadBase
{
private:
    UDP *udp;
    Serial *motorSerial;

    string lastData;
    string udpData;

    void startActivity() override;
    void stopActivity() override;
    int run() override;

public:
    Control();
    ~Control();
};

#endif