#include"../unp.h"

int main(int argc, char *argv[]){
    int sockfd;
    struct sockaddr_in address;

    char message[] = "Hello multicast";

    sockfd = Socket(AF_INET,SOCK_DGRAM,0);

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("192.168.0.108"); //localhost ip address
    address.sin_port = htons(RANDPORT);

    while(1){
        Sendto(sockfd,message,sizeof(message),0,(SA*)&address,sizeof(address));
        sleep(1);
    }
}