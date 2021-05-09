#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

int main()
{
    struct sockaddr_in caddr, saddr;
    int cfd, sfd;
    socklen_t clen = sizeof(caddr);
    pid_t pid;
    int ret;
    char buf[BUFSIZ];

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    listen(sfd, 128);

    while(1)
    {
        cfd = accept(sfd, (struct sockaddr *)&caddr, &clen);
        pid = fork();
        switch (pid){
            case 0:
                close(sfd);
                while(1)
                {
                    ret = read(cfd, buf, sizeof(buf));
                    for(int i=0; i<ret; i++) 
                        buf[i] = toupper(buf[i]);
                    write(cfd, buf, ret);
                    write(STDOUT_FILENO, buf, ret);
                }
                break;
            case -1:
                perror("fork");
                exit(1);
            default:
                close(cfd);
                continue;
        }
    }
    return 0;
}