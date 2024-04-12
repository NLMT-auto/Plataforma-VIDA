#ifndef CONTROL_STRUCUT_H
#define CONTROL_STRUCUT_H
#include <stdint.h>
#include "../../../Utils/road_time.h"

typedef struct{
    road_time_t time;
    const int analogpin = 0;    /*pino no qual o cabo de dados do potenciometro vai ser ligado*/
    double value_in;  /*valor lido pelo potenciometro*/
   double value_out; /*valor depositádo na memoria compartilhada do valor do ângulo*/
}CONTROL_DATA;
#endif
