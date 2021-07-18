#ifndef READPOT_H
#define READPOT_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/road_time.h"
#include <stdint.h>
#include <cmath>


class ReadPot: public ThreadBase 
{
public:
    ReadPot(); // Constructor
    ~ReadPot(); // Desconstructor
    

private:

    void startActivity() override;
    void stopActivity() override;

    PosixShMem *shmem_data; // Data pointer
    int run() override; // Read and function

    road_time_t last_time;
    float last_pot;

};

#endif
