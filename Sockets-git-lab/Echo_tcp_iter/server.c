#include"../unp.h"

void str_echo(int connfd){
    int n;
    char buffer[BUFSIZ];

    again:
    while((n = Recv(connfd,buffer,BUFSIZ,0)) > 0)
        Send(connfd,buffer,n,0);

    if(n < 0)
        goto again;
}

int main(){
    int listenfd, connfd, pid, addrlen3;

    struct sockaddr_in address, cli_address;
    socklen_t addrlen = sizeof(address);

    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_port = htonl(INADDR_ANY);
    address.sin_port = htons(RANDPORT);

    Bind(listenfd,(SA*)&address,sizeof(address));

    Listen(listenfd,3);

    Getsockname(listenfd,(SA*)&address,&addrlen);

    printf("Server's local address is %s:%d\n",
        inet_ntoa(address.sin_addr),htons(address.sin_port));

    for(;;){
        addrlen = sizeof(SA);

        connfd = Accept(listenfd,(SA*)&cli_address,&addrlen);

        Getpeername(connfd,(SA*)&cli_address,&addrlen);

        printf("Client connected at %s:%d\n", 
            inet_ntoa(cli_address.sin_addr), htons(cli_address.sin_port));

        str_echo(connfd);
        close(connfd);
    }
}