#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include "../../Utils/PosixShMem/PosixShMem.h" //biblioteca para uso da memoria Compartilhada
#include "../../Utils/ThreadBase/ThreadBase.h" //biblioteca para multThread
#include <wiringPi.h>                          // biblioteca para uso das GPIO

using namespace std;

class Control : public ThreadBase
{
public:
    Control();
    ~Control();

private:
    PosixShMem *memoriaCompartilhada;
    void startActivity() override;
    void stopActivity() override;
    int run() override;

    CONTROL_DATA myData;
};
#endif
