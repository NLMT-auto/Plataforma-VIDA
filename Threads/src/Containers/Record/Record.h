#ifndef RECORD_H
#define RECORD_H

#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Files/Struct_sensors.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Record : public ThreadBase
{
private:
    void startActivity() override;
    void stopActivity() override;
    int run() override;
    void saveEncoder();
    void saveSteering();

    PosixShMem *memorySharedEncoder;
    PosixShMem *memorySharedSteering;

    Encoder_data encoderData;
    road_time_t lastDataEncoder;
    ostringstream bufferEncoder;
    ofstream outputEncoder;
    long long unsigned int countEncoder;

    Steering_data steeringData;
    road_time_t lastDataSteering;
    ostringstream bufferSteering;
    ofstream outputSteering;
    long long unsigned int countSteering;

public:
    Record();
    ~Record();
};

#endif