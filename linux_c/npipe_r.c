#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[BUFSIZ];

    umask(0);
    fd = open("myfifo", O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("read : %s\n", buf);
    close(fd);

    return 0;
}