#ifndef CONTROL_H
#define CONTROL_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../Estecamento/poten/poten.h"
#include "../Estecamento/poten/poten_struct.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;
class Encoder: public ThreadBase
{
public:
    Encoder();
    ~Encoder();

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
    PosixShMem* potendata;

    void startActivity() override;
    void stopActivity() override;
    int run() override;
};

#endif
