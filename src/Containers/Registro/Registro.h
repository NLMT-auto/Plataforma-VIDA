#ifndef REGISTRO_H
#define REGISTRO_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <iostream>

using namespace std;

class Registro : public ThreadBase
{
private:

    PosixShMem *memoriaCompartilhada;
    void startActivity() override;
    void stopActivity() override;
    int run() override;    

public:
    Registro();
    ~Registro();
};


#endif