#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

//softlink is a shortcut(pointer) to the original file. hardlink is another pathname to the same file

int main(int argc, const char* argv[]){
    //printf("%s\n%s\n%s\n",argv[0],argv[1],argv[2]);
    int input_fd, output_fd, buffer;
    ssize_t ret_in, ret_out;

    if(argc != 3){
        printf("Usage: cp file1 file2");
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if(input_fd == -1){
        perror("open");
        return 2;
    }

    output_fd = open(argv[2], O_WRONLY|O_CREAT, 0644);
    if(output_fd == -1){
        perror("open");
        return 3;
    }

    while((ret_in = read(input_fd, &buffer, BUFSIZ)) > 0){
        ret_out = write(output_fd, &buffer, (ssize_t)ret_in);
        if(ret_out != ret_in){
            perror("write");
            return 4;
        }
    }

    close(input_fd);
    close(output_fd);

    return (EXIT_SUCCESS);
}
