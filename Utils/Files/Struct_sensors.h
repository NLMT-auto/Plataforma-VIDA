#ifndef STRUCT_SENSOR_H
#define STRUCT_SENSOR_H

#include "../Utils/road_time.h"

typedef struct
{
    int leftPulses;
    int rigthPulses;
    int backPulses;
    road_time_t time;
} Encoder_data;

typedef struct
{
    int steering;
    road_time_t time;
} Steering_data;

#endif