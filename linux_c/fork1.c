#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    char* msg;
    int k;

    printf("Process creation\n");
    pid = fork();
    switch(pid){
        case 0:
            msg = "child process is running";
            k = 3;
            break;
        case -1:
            perror("process creation failed\n");
            break;
        default:
            msg = "parent process is running";
            k = 5;
            break;
    }

    while(k>0)
    {
        puts(msg);
        sleep(1);
        k--;
    }

    exit(0);
}