#include <iostream>
#include <cstdlib>
#include "Containers/Control/Control.h"
#include "Containers/ReadMem/ReadMem.h"
#include "Containers/WriteMem/WriteMem.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Control *control = new Control;
    ReadMem *read = new ReadMem();
    WriteMem *write = new WriteMem();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);

    delete control;
    delete read;
    delete write;

    return EXIT_SUCCESS;
}