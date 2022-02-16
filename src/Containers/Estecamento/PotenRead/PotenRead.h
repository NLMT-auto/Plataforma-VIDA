#ifndef POTEN_READ_H
#define POTEN_READ_H
#include "../../../Utils/PosixShMem/PosixShMem.h"
#include "../../../Utils/ThreadBase/ThreadBase.h"
#include <stdint.h>

using namespace std;

class PotenRead: public ThreadBase
{
public:
    PotenRead();
    ~PotenRead();

private:

    void startActivity() override;
    void stopActivity() override;
    int run() override;

    PosixShMem *poten_read_data;
    
};
#endif

/* A função desse arquivo é declarar a classe de leitura dos dados do ṕotenciômetro*/

