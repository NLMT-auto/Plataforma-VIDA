#ifndef POTEN_STRUCUT_H
#define POTEN_STRUCUT_H
#include <stdint.h>
#include "../../../Utils/road_time.h"

typedef struct{
    road_time_t time;
    const int analogpin = 0;    /*pino no qual o cabo de dados do potenciometro vai ser ligado*/
    double value_poten_in = 0;  /*valor lido pelo potenciometro*/
    double value_poten_out = 0; /*valor depositádo na memoria compartilhada do valor do ângulo*/
    double angle_now = 0;       /*valor de angulo medido pelo potenciômetro*/
    double angle_requested = 0; /*valor de angulo solicitado para o motor -> mais usado para mostrar ao usuário*/
}POTEN_DATA;
#endif
