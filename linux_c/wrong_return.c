#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void handler_s(int signo)
{
    printf("recv SIGRTMIN+15\n");
    longjmp(env, 2);
}

int main()
{
    switch (setjmp(env))
    {
        case 0:
            break;
        case 1:
            printf("return from SIGRTMIN+15\n");
            break;
        case 2:
            printf("return from SIGRTIM-15\n");
            break;
        default:
            break;
    }

    signal(SIGRTMIN+15, handler_s);
    signal(SIGRTMIN-15, handler_s);

    while(1);

    return 0;
}