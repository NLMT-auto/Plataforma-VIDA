#ifndef USB_STRUCUT_H
#define USB_STRUCUT_H
#include <stdint.h>
#include "../../Utils/road_time.h"

typedef struct{
    road_time_t time;
    char caracter;
}USB_DATA;
#endif
