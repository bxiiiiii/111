#include <stdio.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int cfd, lfd, sfd, maxfd, maxi, ret, n, i;
	struct sockaddr_in saddr, caddr;
	socklen_t clen;
	fd_set allset, rset;
	char buf[BUFSIZ], str[INET_ADDRSTRLEN];
	int client[FD_SETSIZE];

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(9999);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	lfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));
	listen(lfd, 128);

	FD_ZERO(&allset);
	FD_SET(lfd, &allset);
	maxfd = lfd;
	maxi = -1;
	
	for(i = 0; i < 1024; i++)
		client[i] = -1;

	while(1)
	{
		rset = allset;
		ret = select(maxfd+1, &rset, NULL, NULL, NULL);
		if(FD_ISSET(lfd, &rset))
		{
			clen = sizeof(caddr);
			cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);
			
			printf("connection-- port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));

			FD_SET(cfd, &allset);
			
			for(i = 0; i < FD_SETSIZE; i++)
			{
				if(client[i] == -1)
					{
						client[i] = cfd;
						break;
					}
			}

			if(cfd > maxfd)
				maxfd = cfd;
			
			if(maxi < i)
				maxi = i;

			if(ret == 1)
				continue;

		}
		for(i = 0; i < maxi+1; i++)
		{
			sfd = client[i];
			if(sfd < 0)
				continue;
			if(FD_ISSET(sfd, &rset))
			{
				n = read(sfd, buf, sizeof(buf));
				if(n  == 0)
				{
					close(sfd);
					FD_CLR(sfd, &allset);
					client[i] = -1;
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
