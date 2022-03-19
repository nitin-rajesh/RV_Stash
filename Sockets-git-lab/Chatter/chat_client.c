#include"../unp.h"

void str_cli(FILE *fp, int sockfd){
    char buffer[BUFSIZ];

    while(fgets(buffer,BUFSIZ,fp) != NULL){
        Send(sockfd,buffer,BUFSIZ,0);

        Recv(sockfd,buffer,BUFSIZ,0);

        printf("Server replied: ");
        fputs(buffer,stdout);

    }

    printf("\n%%\n");

}

int main(int argc, char *argv[]){

    int sockfd;

    struct sockaddr_in address;

    if(argc != 2)
        err_sys("usage: a.out <ip>");

    sockfd = Socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_port = htons(RANDPORT);
    inet_pton(AF_INET,argv[1],&address.sin_addr);

    Connect(sockfd, (SA*)&address, sizeof(address));

    str_cli(stdin,sockfd);

}