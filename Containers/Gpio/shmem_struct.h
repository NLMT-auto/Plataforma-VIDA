#ifndef SHMEM_STRUCT
#define SHMEM_STRUCT

#include "../../Utils/road_time.h"


typedef struct          /// < Structure created with a data field and the time that was acquired
{
    road_time_t time;
    float potentiometer;
    float velocity;
}SHMEM_DATA;

#endif
