#ifndef POTEN_WHRITE_H
#define POTEN_WHRITE_H
#include "../../../Utils/PosixShMem/PosixShMem.h"
#include "../../../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>

using namespace std;

class PotenWhrite: public ThreadBase
{
public:
    PotenWhrite();
    ~PotenWhrite();

private:

    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem *poten_whrite;
    
};
#endif

