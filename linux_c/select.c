#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/time.h>

void ti(char *string)
{
    int seconds = time((time_t*)NULL);
    printf("%s, %d\n",string, seconds);
}

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    while(1)
    {
        ti("before");
        ret = select(1, &readfds, NULL, NULL, &timeout);
        switch (ret)
        {
            case 0:
                printf("NO data");
                exit(0);
                break;
            case -1:
                perror("select failed");
            default:
                getchar();
                printf("Data is vailable.\n");
        }
    }

    return 0;
}