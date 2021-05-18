#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[BUFSIZ] = "hello";

    umask(0);
    mkfifo("myfifo", S_IFIFO|0666);
    fd = open("myfifo", O_WRONLY);
    write(fd, buf, sizeof(buf));
    close(fd);

    return 0;
}