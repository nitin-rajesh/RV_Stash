#include"../unp.h"

int main(int argc, const char *argv[]){
    int connfd;

    char *buffer = malloc(BUFSIZ);

    struct sockaddr_in address;

    ssize_t len;

    if(argc < 3){
        err_sys("Pass IP and filename as args");
    }

    connfd = Socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_port = htons(RANDPORT);
    inet_pton(AF_INET, argv[1], &address.sin_addr);

    Connect(connfd, (SA*) &address, sizeof(address));

    Send(connfd,argv[2],sizeof(argv[2]),0);

    while((len = Recv(connfd, buffer, BUFSIZ, 0)) > 0)
        write(1,buffer,len);

    printf("\n%%\n");
    
    return Close(connfd);

}