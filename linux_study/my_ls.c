#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void display_attribute(struct stat buf, char* name)
{
	if(S_ISLNK(buf.st_mode)){
		printf("l");
	}else if(S_ISREG(buf.st_mode)){
		printf("-");
	}else if(S_ISDIR(buf.st_mode)){
		printf("d");
	}else if(S_ISCHR(buf.st_mode)){
		printf("c");
	}else if(S_ISBLK(buf.st_mode)){
		printf("b");
	}else if(S_ISFIFO(buf.st_mode)){
		printf("p");
	}else if(S_ISSOCK(buf.st_mode)){
		printf("s");
	}

	printf(" ");
	
	if(buf.st_mode & S_IRUSR){
		printf("r");
	}else{
		printf("-");
	}
	if(buf.st_mode & S_IWUSR){
		printf("w");
	}else{
		printf("-");
	}
	if(buf.st_mode & S_IXUSR){
		printf("x");
	}else{
		printf("-");
	}

	if(buf.st_mode & S_IRGRP){
		printf("r");
	}else{
		printf("-");
	}

	if(buf.st_mode & S_IWGRP){
		printf("w");
	}else{
		printf("-");
	}
	if(buf.st_mode & S_IXGRP){
		printf("x");
	}else{
		printf("-");
	}

	if(buf.st_mode & S_IROTH){
		printf("r");
	}else{
		printf("-");
	}
	if(buf.st_mode & S_IWOTH){
		printf("w");
	}else{
		printf("-");
	}
	if(buf.st_mode & S_IXOTH){
		printf("x");
	}else{
		printf("-");
	}
}

/*	printf(" ");

	printf("4%d ", buf.st_nlink);

	printf("%8s ", buf.st_uid);
	printf("%8s ", buf.st_gid);

	printf("4%d ", buf.size);

	printf("%s", buf.st_atime);*/


int main(int argc, char** argv)
{
	DIR *dir;
	struct dirent* ddir;
	if(argc == 1)	
	{
		dir = opendir(./);
		ddir = readdir(dir);
		for(int i = 0; ddir->d_name[i] != NULL; i++)
		{
			printf("%s\t",ddir->d_name[i]);
		}
	}

	return 0;
}


































