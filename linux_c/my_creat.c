#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	int fp;
//	fp = open("./testddd", O_CREAT | O_EXCL, S_IWUSR | S_IROTH | S_IXGRP);
	fp = creat("./testdddd",S_IWUSR | S_IROTH| S_IXGRP);
	if(fp == -1)
	{
		perror("creat:");
		exit(1);
	}
	else{
		printf("success");
	}
	return 0;
}
