#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,  char *const *argv)
{
    printf("Inside main\n");
    int res=1;
    pid_t pid=fork();
    //printf("%s %s",argv[1],argv[2]);

    if(pid<0)
    {
        printf("Error generated\n");
    }
    if(pid==0)
    {
        printf("Inside child proces,PID=%d\n",getpid());
        execv("./randsort", argv);
    }
    else{
        printf("Inside parent process ID =%d\n",getpid());
        wait(&res);
        if(WIFEXITED(res)==1)
        {
            printf("Terminates normally\n");
        }
        else{
        printf("AbNormal termination");
        exit(0);
        }

    }
}
