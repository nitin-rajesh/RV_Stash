#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>

#define RANDPORT 15000

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif

typedef struct sockaddr SA;

void err_sys(const char* x){
    perror(x);
    exit(1);
}

int Socket(int domain, int type, int protocol){
    int n;
    if((n = socket(domain,type,protocol)) < 0)
        err_sys("socket error");
    
    return n;
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int n;
    if((n = bind(sockfd,addr,addrlen)) < 0)
        err_sys("bind error");

    return n;
}

int Listen(int socket, int backlog){
    int n;
    if((n = listen(socket,backlog)) < 0)
        err_sys("listen error");

    return n;
}

int Accept(int socket, struct sockaddr * address, socklen_t *address_len){
    int n;
    if((n = accept(socket,address,address_len)) < 0)
        err_sys("accept error");

    return n;
}


int Connect(int socket, const struct sockaddr *address, socklen_t address_len){
    int n;
    if((n = connect(socket,address,address_len)) < 0)
        err_sys("connect error");

    return n;
}

int Open(const char *fname, int oflag){
    int n;
    if((n = open(fname,oflag)) < 0)
        err_sys("file open failed");
    
    return n;
}

int Close(int fildes){

    return close(fildes);
}

ssize_t Send(int socket, const void *buffer, size_t length, int flags){
    ssize_t n;
    if((n = send(socket, buffer, length, flags)) < 0)
        err_sys("send failed");

    return n;
}

ssize_t Recv(int socket, void *buffer, size_t length, int flags){
    ssize_t n;
    if((n = recv(socket, buffer, length, flags)) < 0)
        err_sys("recv failed");

    return n;
}

ssize_t Sendto(int socket, const void *buffer, size_t length, int flags,
    const struct sockaddr *dest_addr, socklen_t dest_len){

    ssize_t n;
    if((n = sendto(socket,buffer,length,flags,dest_addr,dest_len)) < 0)
        err_sys("sendto failed");
    
    return n;
}

ssize_t Recvfrom(int socket, void *buffer, size_t length, int flags,
    struct sockaddr *address, socklen_t *address_len){
    
    ssize_t n;
    if((n = recvfrom(socket,buffer,length,flags,address,address_len)) < 0)
        err_sys("recvfrom failed");

    return n;
}

int Setsockopt(int socket, int level, int option_name, 
    const void *option_value, socklen_t option_len){
    
    int n;
    if((n = setsockopt(socket,level,option_name,option_value, option_len))< 0)
        err_sys("setsockopt failed");

    return n;
}

int Getsockname(int socket, struct sockaddr *address, socklen_t *address_len){
    int n;
    if((n = getsockname(socket,address,address_len)) < 0)
        err_sys("getsockname failed");

    return n;
}

int Getpeername(int socket, struct sockaddr *address, socklen_t *address_len){
    int n;
    if((n = getpeername(socket,address,address_len)) < 0)
        err_sys("getpeername failed");

    return n;
}