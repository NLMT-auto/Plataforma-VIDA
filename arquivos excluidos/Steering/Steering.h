#ifndef STEERING_H
#define STEERING_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>

class Steering: public ThreadBase
{
public:
    Steering(int pin1, int pin2, int pwm);
    ~Steering();

private:
    int pin1;
    int pin2;
    int pwm;

    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem* steering_data;
};
#endif
