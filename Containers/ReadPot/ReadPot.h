#ifndef READPOT_H
#define READPOT_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>
#include <cmath>

class ReadPot: public ThreadBase 
{
public:
    ReadPot(); // Constructor
    ~ReadPot(); // Desconstructor
    

private:

    PosixShMem *potentiometer_data; // Data pointer
    void startActivity() override;
    void stopActivity() override; 
    int run() override; // Read and function
};

#endif
