#ifndef CONTROL_H
#define CONTROL_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"

class Control: public ThreadBase 
{
public:
    Control(); // Constructor
    ~Control(); // Desconstructor

private:

    PosixShMem *potentiometer_data; // Data pointer 
    PosixShMem *write_data; // Data pointer
    void startActivity() override;
    void stopActivity() override; 
    int run() override; // Read function
    
};

#endif
