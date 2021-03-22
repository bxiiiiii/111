#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv, char **envp)
{
    printf("Process image\n");
    printf("My pid is %d,parentpid is %d\n", getpid(), getppid());

    /*for(int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);*/
    return 0;
}