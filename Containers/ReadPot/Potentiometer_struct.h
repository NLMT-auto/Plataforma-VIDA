#ifndef POTENTIOMETER_STRUCT_H
#define POTENTIOMETER_STRUCT_H
#include <stdint.h>
#include "../../../Utils/road_time.h"

typedef struct
{
    road_time_t time;
    uint16_t potentiometer;
} Timestamped_POTENTIOMETER_DATA;

#endif
