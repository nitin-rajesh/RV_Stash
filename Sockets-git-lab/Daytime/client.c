#include"../unp.h"
#define MAXLINE 128

int main(int argc, const char* argv[]){
    int sockfd, n;
    char recvline[MAXLINE + 1];

    struct sockaddr_in servaddr;

    if(argc != 2)
        err_sys("usage: a.out <ip>");

    sockfd = Socket(AF_INET,SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    if(inet_pton(AF_INET, argv[1],&servaddr.sin_addr) <= 0)
        err_sys("inet_pton error");

    Connect(sockfd,(SA*)&servaddr,sizeof(servaddr));

    while((n = read(sockfd,recvline,MAXLINE)) > 0){
        recvline[n] = 0;
        if(fputs(recvline,stdout) == EOF)
            err_sys("fputs error");
    }
    if(n < 0)
        err_sys("read error");
    exit(0);
}