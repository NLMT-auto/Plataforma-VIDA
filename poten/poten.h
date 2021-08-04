#ifndef POTEN_H
#define POTEN_H
#include "../Utils/PosixShMem/PosixShMem.h"
#include "../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>

using namespace std;

class poten: public ThreadBase
{
public:
    poten();
    ~poten();

private:

    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem* poten_data;
    
};
#endif

