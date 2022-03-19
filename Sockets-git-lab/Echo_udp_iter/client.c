#include"../unp.h"

void str_cli(FILE *fp, int sockfd, SA* serv_address, socklen_t serv_len){
    ssize_t n;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFSIZ];

    while(fgets(buffer, BUFSIZ, fp) != 0){
        Sendto(sockfd,buffer,BUFSIZ,0,serv_address,serv_len);

        Recvfrom(sockfd, buffer, BUFSIZ, 0, NULL, NULL);
    
        printf("Server replied: ");
        fputs(buffer, stdout);

    }
}

int main(int argc, char *argv[]){
    int sockfd;

    struct sockaddr_in serv_address;

    if(argc != 2)
        err_sys("usage: a.out <ip>");

    sockfd = Socket(AF_INET,SOCK_DGRAM,0);

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(RANDPORT);
    inet_pton(AF_INET,argv[1],&serv_address.sin_addr);

    str_cli(stdin,sockfd,(SA*)&serv_address,sizeof(serv_address));

}