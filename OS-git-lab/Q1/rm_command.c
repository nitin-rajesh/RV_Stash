#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

//softlink is a shortcut(pointer) to the original file. hardlink is another pathname to the same file

int main(int argc, const char* argv[]){
    int output_fd = unlink(argv[1]);
    if(argc != 2){
        printf("Usage: rm file1");
        return 1;
    }
    if(output_fd == -1){
        perror("unlink error");
        return 3;
    }
}