#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc < 2){
		printf("my_chmod <filename>");
	}

	struct stat *buf;
	if((lstat(argv[1], buf) == -1))
	{
		perror("stat:");
		exit(1);
	}else
	{
		printf("dev : %ld\n", buf->st_dev);
		printf("ino : %ld\n", buf->st_ino);
		printf("mode : %d\n", buf->st_mode);
		printf("nlink : %ld\n", buf->st_nlink);
		printf("uid : %d\n", buf->st_uid);
		printf("gid : %d\n", buf->st_gid);
		printf("size : %ld\n", buf->st_size);
		printf("blksize : %ld\n", buf->st_blksize);
		printf("blcoks : %ld\n", buf->st_blocks);
		printf("atime : %ld\n", buf->st_atime);
		printf("mtime : %ld\n", buf->st_mtime);
		printf("ctime : %ld\n", buf->st_ctime);
	}
	return 0;
}