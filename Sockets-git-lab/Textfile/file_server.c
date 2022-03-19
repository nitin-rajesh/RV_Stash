#include"../unp.h"

int main(){
    int sockfd, connfd, fd;
    ssize_t len;
    socklen_t addrlen;

    char *buffer = malloc(BUFSIZ);

    char fname[256];

    struct sockaddr_in address;

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(RANDPORT);

    Bind(sockfd, (SA*) &address, sizeof(address));

    Listen(sockfd, 3);

    addrlen = sizeof(struct sockaddr_in);

    connfd = Accept(sockfd, (SA*)&address, &addrlen);

    if(connfd > 0)
        printf("Client %s is connected",inet_ntoa(address.sin_addr));

    Recv(connfd,fname,255,0);

    printf("\nRequest for filename %s recvd\n",fname);

    fd = Open(fname, O_RDONLY);

    while((len = read(fd,buffer,BUFSIZ)) > 0)
        Send(connfd,buffer,BUFSIZ,0); 

    printf("Request complete\n");

    Close(connfd);

    return Close(sockfd);

}