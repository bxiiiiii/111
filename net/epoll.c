#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/epoll.h>

#define OPEN_MAX 1024

int main()
{
	int cfd, lfd, sfd, ret, n, i, maxi, efd, nready;
	struct sockaddr_in caddr, saddr;
	char buf[BUFSIZ], str[INET_ADDRSTRLEN];
	socklen_t clen;

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(9999);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	lfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
	listen(lfd, 128);

    struct epoll_event tep, ep[OPEN_MAX];

    efd = epoll_create(OPEN_MAX);

    tep.events = EPOLLIN;
    tep.data.fd = lfd;

    ret = epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &tep);

    while(1)
    {
        nready = epoll_wait(efd, ep, OPEN_MAX, -1);
        for(i = 0; i < nready; i++)
        {
            if(!ep[i].events & EPOLLIN)
                continue;
            if(ep[i].data.fd == lfd)
            {
                clen = sizeof(caddr);
                cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);

                printf("connection--port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));

                tep.data.fd = cfd;
                tep.events = EPOLLIN;
                ret = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &tep);
            }
            else
            {
                sfd = ep[i].data.fd;
                n = read(sfd, buf, sizeof(buf));
                if(n == 0)
                {
                    ret = epoll_ctl(efd, EPOLL_CTL_DEL, sfd, NULL);
                    close(sfd);
                }
                else
                {
                    for(int j = 0; j < n; j++)
						buf[j] = toupper(buf[j]);
					write(STDOUT_FILENO, buf, n);
					write(sfd, buf, n);
                }
            }
        }
    }

    close(lfd);
    return 0;
}