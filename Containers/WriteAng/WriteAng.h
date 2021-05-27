#ifndef WRITEANG_H
#define WRITEANG_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"

class WriteAng: public ThreadBase 
{
public:
    WriteAng(); // Constructor
    ~WriteAng(); // Desconstructor

private:

    PosixShMem *shmem_data; // Data pointer
    void startActivity() override;
    void stopActivity() override; 
    int run() override; // Read function
    
};

#endif
