#ifndef CONTROL_H
#define CONTROL_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../files/control_struct.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;
class Control: public ThreadBase
{
public:
    Control();
    ~Control();

private:

    PosixShMem *controlData;
    void startActivity() override;
    void stopActivity() override;
    int run() override;

    CONTROL_DATA myData;
};
#endif
