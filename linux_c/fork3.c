#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    switch(pid) {
        case 0:
            printf("A background process , Pid:%d, parentid:%d\n",getpid(), getppid());
            sleep(3);
            printf("A background process , Pid:%d, parentid:%d\n",getpid(), getppid());
            break;
        case -1:
            perror("process creation failed\n");
            exit(-1);
        default:
        printf("I am parent process, my pid is %d\n", getpid());
        exit(0);
    }

    return 0;
}