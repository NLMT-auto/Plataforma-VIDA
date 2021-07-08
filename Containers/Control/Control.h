#ifndef CONTROL_H
#define CONTROL_H

#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include "../../Utils/road_time.h"
#include <stdint.h>
#include <cmath>


class Control: public ThreadBase 
{
public:
    Control(); // Constructor
    ~Control(); // Desconstructor
    

private:

    void startActivity() override;
    void stopActivity() override;

    PosixShMem *shmem_data; // Data pointer
    int run() override; // Read and function

    road_time_t last_time;
    float last_pot;

};

#endif