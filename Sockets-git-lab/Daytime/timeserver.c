#include"../unp.h"
#include<time.h>
#include<string.h>
#define MAXLINE 128

int main(int argc, const char* argv[]){
    int listenfd, connfd;
    time_t ticks;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];

    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd,3);

    for(;;){
        connfd = Accept(listenfd,(SA*) NULL, NULL);

        ticks = time(NULL);

        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
        write(connfd, buff,strlen(buff));

        close(connfd);
    }
}