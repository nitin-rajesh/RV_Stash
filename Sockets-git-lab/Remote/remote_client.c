#include"../unp.h"
#include<string.h>

void str_cli(FILE *fp, int sockfd, char *buffer){
    ssize_t n;
    Send(sockfd, buffer, BUFSIZ, 0);

    while((n=Recv(sockfd,buffer,BUFSIZ,0)) > 0){
        fputs(buffer,stdout);
    }

    printf("%%\n");
}

char* concatArgs(int argc, char *argv[]){
    char* command = malloc(BUFSIZ);
    command[0] = '\0';
    for (int i = 2; i < argc; i++){
        strcat(command,argv[i]);
        strcat(command, " ");
    }

    return command;
}

int main(int argc, char *argv[]){

    int sockfd;

    struct sockaddr_in address;

    if(argc < 2)
        err_sys("usage: a.out <ip> <command>");

    char *buffer = concatArgs(argc, argv);
    printf("%s",buffer);

    sockfd = Socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_port = htons(RANDPORT);
    inet_pton(AF_INET,argv[1],&address.sin_addr);

    Connect(sockfd, (SA*)&address, sizeof(address));

    str_cli(stdin,sockfd,buffer);

}