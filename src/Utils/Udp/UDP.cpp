#include "UDP.h"

UDP::UDP(){      
       
    // CriaÃ§o do socket UDP
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        cerr << "Erro ao criar o socket" << endl;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Configurações do servidor UDP
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Associa o socket ao endereço e porta
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        cerr << "Erro ao associar o socket ao endereco" << endl;
    }

    len = sizeof(cliaddr);
}

UDP::~UDP(){
    close(sockfd);
}

string UDP::read(){

    int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
   
    return buffer;
}

