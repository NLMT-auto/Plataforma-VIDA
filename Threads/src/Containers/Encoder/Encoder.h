#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <sstream>
#include <wiringPi.h>

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/Serial/Serial.h"
#include "../../Files/Struct_sensors.h"
#include "../../Files/DefinePin.h"

using namespace std;

class Encoder : public ThreadBase
{
private:
    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem *memoryShared;
    Encoder_data encoderData;
    string buffer;

    Serial *encoderSerial;

public:
    Encoder();
    ~Encoder();
};

#endif