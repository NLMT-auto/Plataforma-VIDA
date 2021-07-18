#ifndef CONTROL_H
#define CONTROL_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"

class Control: public ThreadBase
{
public:
    Control();
    ~Control();

private:
    PosixShMem* steering_data;
    PosixShMem* potentiometer_data;

    void startActivity() override;
    void stopActivity() override;
    int run() override;
};
#endif
