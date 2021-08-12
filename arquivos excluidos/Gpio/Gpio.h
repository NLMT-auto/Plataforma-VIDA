#ifndef GPIO_H
#define GPIO_H
#include <semaphore.h> 
#include "../Potentiometer/Potentiometer.h"
#include "../Control/Control.h"

class Gpio
{
private:
    Control *control;
    Potentiometer *potentiometer;
    static sem_t *sem_pt;
    
public:
    Gpio();
    ~Gpio();
    
    static void lockGpio();
    static void unlockGpio();
};
#endif
