
//Structure that with a data field and the time that was acquired 
//In this example the data is from a loop counter 

#ifndef TEST_STRUCT
#define TEST_STRUCT
#include <time.h>
#include "../../../Utils/road_time.h"
typedef struct
{
    //int velocity;
    uint64_t contador;
}TEST_DATA;


typedef struct
{
    
    double velocidade;
    double time1;
    double t5, t4;
    road_time_t time;
    TEST_DATA data;
}TIMESTAMPED_TEST_DATA;



#endif