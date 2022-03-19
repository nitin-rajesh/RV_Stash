#include"../unp.h"

int main(int argc, char *argv[]){

    int sockfd;
    socklen_t addrlen;

    char msgbuf[BUFSIZ];
    u_int yes = 1;

    struct ip_mreq mreq;
    struct sockaddr_in address;

    sockfd = Socket(AF_INET,SOCK_DGRAM,0);

    Setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(RANDPORT);

    Bind(sockfd,(SA*)&address,sizeof(address));

    mreq.imr_multiaddr.s_addr = inet_addr("192.168.0.108"); //localhost ip address
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

   // Setsockopt(sockfd,IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

    while (1)
    {
        addrlen = sizeof(address);
        Recvfrom(sockfd, msgbuf,BUFSIZ,0,(SA*) &address, &addrlen);
        printf("%s\n",msgbuf);

    }

}