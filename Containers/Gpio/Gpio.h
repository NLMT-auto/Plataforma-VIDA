#ifndef GPIO_H
#define GPIO_H
#include <semaphore.h> 
#include "../Potentiometer/Potentiometer.h"

class Gpio
{
private:
    Potentiometer *potentiometer;
    static sem_t *sem_pt;
    
public:
    Gpio();
    ~Gpio();
    
    static void lockGpio();
    static void unlockGpio();
};
#endif
