#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in caddr, saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    inet_pton(AF_INET, "127.0.0.1", &saddr.sin_addr.s_addr);
    int c_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    int ret = connect(c_sock_fd, (struct sockaddr* )&saddr, sizeof(saddr));

int ccc = 10;
char buf[BUFSIZ];
    while(ccc--)
    {
        write(c_sock_fd, "hello", 5);
        ret = read(c_sock_fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
    }
    return 0;
}