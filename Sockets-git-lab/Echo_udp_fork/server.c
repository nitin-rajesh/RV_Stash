#include"../unp.h"

void str_echo(int sockfd, SA* cli_address, socklen_t cli_len){
    ssize_t n;
    int pid;
    char buffer[BUFSIZ];

    socklen_t addrlen;

    for(;;){
        addrlen = cli_len;
        n = Recvfrom(sockfd,buffer,BUFSIZ,0,cli_address,&addrlen);
        
        if((pid = fork()) == 0)
            Sendto(sockfd, buffer, n, 0, cli_address,addrlen);
    }
}

int main(){
    int sockfd;
    struct sockaddr_in address, cli_address;

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(RANDPORT);

    Bind(sockfd,(SA*)&address,sizeof(address));

    str_echo(sockfd,(SA*)&cli_address,sizeof(address));
}