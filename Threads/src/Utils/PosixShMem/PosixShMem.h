#ifndef DEF_POSIXSHMEM_H
#define DEF_POSIXSHMEM_H

#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>


class PosixShMem
{
public:
    PosixShMem(const char *name, int size); /// < Constructor. Receives the name and size of the created memory
    virtual ~PosixShMem();                 /// < Desconstructor

    virtual void *read();
    virtual void read(void *mem, int size);                              /// < Read the memory 
    virtual void write(void *data, int size, unsigned long offset = 0); /// < Write the memory  

    virtual void lockMemory();       /// < Locks the access to memory
    virtual void unlockMemory();    /// < Unlocks the access to memory

private:

    void *shm_pt;            /// < Shared memory parameter
    const char *shm_name;   /// < Shared memory parameter
    int shm_fd;            /// < Shared memory parameter

    sem_t *sem_pt;           /// < Semaphore parameter for controlling access to memory
    char sem_name[255];     /// < Semaphore parameter for controlling access to memory

};

#endif
