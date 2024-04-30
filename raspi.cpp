#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define PORT 5005
#define BUFFER_SIZE 1024

int main() {

    int fd = serialOpen("/dev/ttyS0", 115200);

    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);
    char buffer[BUFFER_SIZE];

    // CriaÃ§o do socket UDP
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Erro ao criar o socket" << std::endl;
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Configuraï¿½ï¿½es do servidor UDP
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Associa o socket ao endereï¿½o e porta
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Erro ao associar o socket ao endereï¿½o" << std::endl;
        return -1;
    }

    std::cout << "Servidor UDP esperando por mensagens..." << std::endl;

    // Loop para receber mensagens
    while (true) {
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        //std::cout << buffer << std::endl;
        serialPrintf(fd, "%s\n", buffer);
    }

    close(sockfd);
    serialClose(fd);


    return 0;
}
