#include <iostream>

#include "Containers/Control/Control.h"
#include "Containers/Encoder/Encoder.h"
#include "Containers/Steering/Steering.h"
#include "Containers/Record/Record.h"

using namespace std;

int main(int argc, char *argv[])
{
    Control *control = new Control();
    Encoder *encoder = new Encoder();
    Steering *steering = new Steering();
    Record *registro = new Record();

    int quit = -1;
    do
    {
        cin >> quit;
    } while (quit != 0);

    delete control;
    delete encoder;
    delete steering;
    delete registro;

    return EXIT_SUCCESS;
}