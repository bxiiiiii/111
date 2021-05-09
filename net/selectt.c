#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int lfd, cfd, maxfd, n, ret;
    struct sockaddr_in saddr, caddr;
    fd_set rset, allset;
    char buf[BUFSIZ];
    socklen_t clen;

	bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    maxfd = lfd;

    bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));

    listen(lfd, 128);

    FD_ZERO(&allset);
    FD_SET(lfd, &allset);
    
    while(1)
    {
        rset = allset;
        ret = select(maxfd+1, &rset, NULL, NULL, NULL);
        if(FD_ISSET(lfd, &rset))
        {
            clen = sizeof(caddr);
            cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
            FD_SET(cfd, &allset);

            if(maxfd < cfd)
                maxfd = cfd;

            if(ret == 1)
                continue;
        }

        for(int i = lfd+1; i <= maxfd; i++)
        {
            if(FD_ISSET(i, &rset))
            {
                n = read(cfd, buf, sizeof(buf));
                if(n == 0)
                {
                    close(i);
                    FD_CLR(i, &allset);
                }
                else
                {
                    write(STDOUT_FILENO, buf, n);
                    for(int j = 0; j < n; j++)
                        buf[j] = toupper(buf[j]);
                    write(i, buf, n);
                }
            }
            
        }
    }

    close(lfd);
    return 0;
}
