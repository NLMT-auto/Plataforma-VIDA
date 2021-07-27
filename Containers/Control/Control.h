#ifndef CONTROL_H
#define CONTROL_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;
class WriteMem: public ThreadBase
{
public:
    WriteMem();
    ~WriteMem();

private:

    PosixShMem *data;
    void startActivity() override;
    void stopActivity() override;
    int run() override;
    
    
};

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
