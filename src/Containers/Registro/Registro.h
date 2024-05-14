#ifndef REGISTRO_H
#define REGISTRO_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/Serial/Serial.h"
#include "../../Files/Struct_encoders.h"
#include "../../Files/DefinePin.h"
#include <iostream>

using namespace std;

class Registro : public ThreadBase
{
private:
        
    void startActivity() override;
    void stopActivity() override;
    int run() override;   

    PosixShMem *memoriaCompartilhada;   
    Encoder encoderData; 

    Serial *serialMotor;
    Serial *serialEncoder;

public:
    Registro();
    Registro(Serial *serialEncoder, Serial *serialMotor);
    ~Registro();
};


#endif