#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    printf("Proccess Creation \n");
    pid = fork();
    switch(pid){
        case 0:
            printf("Child process is running,Curpid is %d, parentpid is %d\n", pid, getppid());
            break;
        case -1:
            perror("Process creation failed\n");
        default:
        printf("Parent process is running, childpid is %d, parentpid is %d\n", pid, getpid());
        break;
    }
    exit(0);
}