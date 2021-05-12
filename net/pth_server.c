#include <stdio.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void *obj(void *arg)
{
    int n, j;
    int *cfd = (int*)arg;
    char buf[BUFSIZ];
    while(1)
    {
        n = read(*cfd, buf, sizeof(buf));
        if(n == 0)
        {
            printf("connection terminated.\n");
            break;
        }
        else
        {
            for(j = 0; j < n; j++)
                buf[j] = toupper(buf[j]);
            write(STDOUT_FILENO, buf, n);
            write(*cfd, buf, n);
        }
    }
    close(*cfd);
    return (void *)0;
}

int main()
{
    int lfd, cfd;
    socklen_t clen;
    char str[INET_ADDRSTRLEN];
    struct sockaddr_in caddr, saddr;

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(7777);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
    listen(lfd, 128);

    pthread_t tid;
    while(1)
    {
        clen = sizeof(caddr);
        cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
        printf("connection -- port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));
        pthread_create(&tid, NULL, obj, (void *)&cfd);
        pthread_detach(tid);
    }
    return 0;
}