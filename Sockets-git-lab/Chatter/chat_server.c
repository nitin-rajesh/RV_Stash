#include"../unp.h"

void str_echo(int connfd, int port){
    int n, len;
    char *buffer = malloc(BUFSIZ);

    struct sockaddr_in address;

    again:
    while((n = recv(connfd,buffer,BUFSIZ,0)) > 0){
        printf("From client at port %d: ", port);
        fputs(buffer,stdout);

        fgets(buffer,BUFSIZ,stdin);

        Send(connfd,buffer,n,0);
    }

    if(n < 0)
        goto again;
}

int main(){
    int listenfd, connfd, pid;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(RANDPORT);

    Bind(listenfd,(SA*)&address,sizeof(address));

    Listen(listenfd, 3);

    Getsockname(listenfd,(SA*)&address,&addrlen);
    printf("Server listening on port %d\n",address.sin_port);

    for(;;){
        addrlen = sizeof(struct sockaddr_in);
        connfd = Accept(listenfd,(SA*)&address,&addrlen);
        printf("New client on port %d\n",address.sin_port);

        if((pid = fork()) == 0){
            Close(listenfd);
            str_echo(connfd,address.sin_port);
            exit(0);
        }

        close(connfd);
    }
}