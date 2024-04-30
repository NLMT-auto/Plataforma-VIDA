#ifndef UDP_H
#define UDP_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5005
#define BUFFER_SIZE 1024

using namespace std;

class UDP
{
    private:
        sockaddr_in servaddr;
        sockaddr_in cliaddr;
        socklen_t len;
        int sockfd;
        char buffer[BUFFER_SIZE];      

    public:
        UDP();
        ~UDP();
        string read();
};

#endif