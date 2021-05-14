#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <wait.h>
#include <string.h>

void catch_child(int signum)
{
    while((waitpid(0, NULL,WNOHANG))>0);

    return ;
}

int main()
{
    struct sockaddr_in caddr, saddr;
    int cfd, sfd;
    socklen_t clen = sizeof(caddr);
    pid_t pid;
    int ret;
    char buf[BUFSIZ], str[INET_ADDRSTRLEN];;

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    listen(sfd, 128);

    while(1)
    {
        cfd = accept(sfd, (struct sockaddr *)&caddr, &clen);
        printf("connection -- port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));
        pid = fork();
        switch (pid){
            case 0:
                close(sfd);
                while(1)
                {
                    ret = read(cfd, buf, sizeof(buf));
                    if(ret == 0)
                    {
                        printf("connection terminated.\n");
                        break;
                    }
                    else
                    {
                        for(int i=0; i<ret; i++) 
                            buf[i] = toupper(buf[i]);
                        write(cfd, buf, ret);
                        write(STDOUT_FILENO, buf, ret);
                    }
                }
                break;
            case -1:
                perror("fork");
                exit(1);
            default:
            {    
                struct sigaction act;
                act.sa_handler = catch_child;
                sigemptyset(&act.sa_mask);
                act.sa_flags = 0;
                
                sigaction(SIGCHLD, &act, NULL);
                close(cfd);
                continue;
            }
        }
    }
    return 0;
}