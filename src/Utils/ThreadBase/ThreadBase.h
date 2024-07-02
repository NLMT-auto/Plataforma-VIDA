#ifndef THREADBASE_H
#define THREADBASE_H

#include <pthread.h>
#include <time.h>

class ThreadBase
{
private:
    pthread_t thread;                     /// < Thread Pointer
    struct timespec tim3, tim4;          /// < Times used to stop the loop
    static void *start(void *param);    /// < Pointer to function that starts the thread

protected:
    int is_running;                      /// < Indicator that the thread is running
    int is_alive;                       /// < Indicator that the thread is alive
    struct timespec tim1, tim2;        /// < Thread sleep time

    ThreadBase();                       /// < Class constructor
    virtual ~ThreadBase();             /// < Class desconstructor
    virtual int run() = 0;            /// < Thread function

public:
    virtual void startActivity();        /// < Function when starting a thread
    virtual void stopActivity();        /// < Function when ending a thread

};

#endif
