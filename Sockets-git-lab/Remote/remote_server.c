#include"../unp.h"

void remote_command(int connfd){
    ssize_t n;
    char buffer[BUFSIZ];

    again:
    while((n = Recv(connfd,buffer,BUFSIZ,0)) > 0){
        FILE *pipe = popen(buffer,"r");

        while(fgets(buffer,BUFSIZ,pipe) != NULL)
            Send(connfd, buffer, n, 0);
        
        exit(0);
        
    }
    if(n < 0)
        goto again;
}

int main(){
    int listenfd, connfd, fd, pid;
    socklen_t addrlen;

    struct sockaddr_in address;

    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(RANDPORT);

    Bind(listenfd, (SA*)&address,sizeof(address));

    Listen(listenfd, 3);

    for(;;){
        addrlen = sizeof(struct sockaddr_in);
        connfd = Accept(listenfd,(SA*)&address,&addrlen);

        printf("Client %s:%d connected\n",
            inet_ntoa(address.sin_addr),htons(address.sin_port));

        if((pid = fork()) == 0){
            close(listenfd);
            remote_command(connfd);
            exit(0);
        }

        close(connfd);
    }
}