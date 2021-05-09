#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <poll.h>

#define OPEN_MAX 1024

int main()
{
	int cfd, lfd, sfd, ret, n, i, maxi;
	struct sockaddr_in caddr, saddr;
	char buf[BUFSIZ], str[INET_ADDRSTRLEN];
	struct pollfd client[OPEN_MAX];
	socklen_t clen;

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(9999);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	lfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
	listen(lfd, 128);

	for(i = 0; i < OPEN_MAX ; i++)
		client[i].fd = -1;

	client[0].fd = lfd;
	client[0].events = POLLIN;
	maxi = 0;

	while(1)
	{
		ret = poll(client, maxi+1, -1);
		if(client[0].revents & POLLIN)
		{
			clen = sizeof(caddr);
			cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
			printf("connection--port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));

			for(i = 1; i < OPEN_MAX; i++)
			{
				if(client[i].fd < 0)
				{
					client[i].fd = cfd;
					client[i].events = POLLIN;
					break;
				}
			}

			if(maxi < i)
				maxi = i;

			if(ret == 1)
				continue;
		}

		for(i = 1; i < maxi+1; i++)
		{
			sfd = client[i].fd;
			if(sfd > 0)
			{
				n = read(sfd, buf, sizeof(buf));
				if(n == 0)
				{
					close(sfd);
					client[i].fd = -1;
				}
				else
				{
					for(int j = 0; j < n; j++)
						buf[j] = toupper(buf[j]);
					write(STDOUT_FILENO, buf, n);
					write(sfd, buf, n);
				}

				if(ret == 1)
					break;
			}
		}
	}

	close(lfd);
	return 0;
}
