#ifndef SETPOINT_H
#define SETPOINT_H

#include "../../../Utils/PosixShMem/PosixShMem.h"
#include "../../../Utils/ThreadBase/ThreadBase.h"

using namespace std;
class SetPoint: public ThreadBase
{
public:

    SetPoint();
    ~SetPoint();

private:

    PosixShMem *data;
    void startActivity() override;
    void stopActivity() override;
    int run() override;
    
    
};

#endif