#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>

#include "../../Utils/UDP/UDP.h"
#include "../../Utils/Serial/Serial.h"
#include "../../Utils/ThreadBase/ThreadBase.h"


using namespace std;

class Controle : public ThreadBase
{
    private:
        UDP *udp;
        Serial *motorSerial;

        void startActivity() override;
        void stopActivity() override;
        int run() override;

    public:
        Controle();
        ~Controle();
};

#endif