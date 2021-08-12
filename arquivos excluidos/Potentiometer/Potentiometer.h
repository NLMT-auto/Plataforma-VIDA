#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>

class Potentiometer: public ThreadBase
{
public:
    Potentiometer(int deviceAddr, int channel);
    ~Potentiometer();

private:
    int i2cFile;
    int deviceAddr;
    int channel;
    unsigned char writeBuf[3] = {0};

    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem* potentiometer_data;

    void openI2CBus(char* bus);
    void setI2CSLAVE(int deviceAddr);
    void configDevice(unsigned int config);
    uint16_t readVoltage();
};
#endif