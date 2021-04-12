#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in addr, caddr;
    char buf[BUFSIZ];
    int ret, i;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int s_sock_fd = socket(AF_INET, SOCK_STREAM,0);

    bind(s_sock_fd, (struct sockaddr* )&addr, sizeof(addr));

    listen(s_sock_fd, 20);

    socklen_t caddr_len = sizeof(caddr_len);

    int c_sock_fd = accept(s_sock_fd, (struct sockaddr*)&caddr,&caddr_len);

while(1){
    ret = read(c_sock_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, ret);
    for(i = 0; i < sizeof(buf); i++)
        buf[i] = toupper(buf[i]);

    write(c_sock_fd, buf, ret);
}
    close(s_sock_fd);
    close(c_sock_fd);

    return 0;
}
