#include "ThreadBase.h"
#include <iostream>
#include <cstdint>

using namespace std; 

ThreadBase::ThreadBase()        /// < Constructor: starts the indicators
{
    this->is_running = 0;
    this->is_alive = 0;
}

ThreadBase::~ThreadBase()       /// < Desconstructor 
{

}

void *ThreadBase::start(void *param)  /// < Function that returns a pointer to a function that a thread will execute
{
    ThreadBase *pto = (ThreadBase*) param;
    return (void*)(intptr_t)pto->run();
}

void ThreadBase::startActivity()    /// < Creating a thread
{
    int pt = pthread_create(&this->thread, NULL, this->start, (void*)this);  /// < Pointer saved in the "thread" parameter
    if(pt)      /// < Checks whether the thread was created correctly
    {
        cerr << "Unable to create thread." << endl;
    }
}

void ThreadBase::stopActivity()
{
    if(this->is_alive)
    {
        this->is_alive = 0;
        this->tim3.tv_sec = 0;
        this->tim4.tv_nsec = 100000000L;

        while(this->is_running)         /// < It'll wait for the thread to finish the loop to stop it
        {
            nanosleep(&this->tim3, &this->tim4);
        }
    }    
}
