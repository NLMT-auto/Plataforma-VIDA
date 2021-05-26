#ifndef DATA_STRUCT
#define DATA_STRUCT

#include "../Utils/road_time.h"

typedef struct          /// < Structure created with a data field and the time that was acquired
{
    road_time_t time;
    double potentiometer;
    double velocity;
}WRITE_DATA;

#endif
