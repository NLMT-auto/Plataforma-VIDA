#ifndef STEERING_STRUCT_H
#define STEERING_STRUCT_H
#include <stdint.h>
#include "../../Utils/road_time.h"

typedef struct
{
    road_time_t time;
    bool direction;
    uint8_t speed;
} Timestamped_STEERING_DATA;

#endif
