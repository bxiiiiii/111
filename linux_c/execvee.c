#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv, char** envp)
{
    pid_t pid;
    int stat_val;

    pid = fork();

    switch (pid) {
        case -1:
            perror("process creation failed\n");
            exit(1);
        case 0:
            printf("child pro\n");
            printf("my pid is %d, parentpid is %d\n",getpid(), getppid());
            execve("pro", argv, envp);
            printf("never get here\n");
            exit(0);
        default:
            printf("parent pro\n");
            printf("my id is %d\n", getpid());
            break;
    }
    wait(&stat_val);
    exit(0);
}