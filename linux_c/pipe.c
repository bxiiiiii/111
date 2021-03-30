#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    pid_t pid;
    char buf[1024];
    int fd[2];
    char* p = "lllll";

    pipe(fd);

    pid = fork();
    switch (pid){
        case 0:
            close(fd[1]);
            int len = read(fd[0], buf, sizeof(buf));
            write(STDOUT_FILENO, buf, len);
            close(fd[0]);
            break;
        default:
            close(fd[0]);
            write(fd[1], p, strlen(p));
            wait(NULL);
            close(fd[1]);
            break;
    }

    return 0;
}