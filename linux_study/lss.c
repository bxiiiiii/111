#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define PARAM_NONE 0
#define RARAM_A 1
#define PARAM_L 1
#define MAXROWLEN 80

int g_leave_len = MAXROWLEN;
int g_maxlen;
int files_num;
int file_num[100];

void my_err(const char* err_string, int line)
{
    fprintf(stderr, "line : %d ", line);
    perror(err_string);
    exit(1);
}

/*void display_attribute(struct stat buf, char * name)
{
    //char buf_time[32];
    struct passwd* psd;
    struct group* grp;

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
        printf("f");
    }else if(S_ISSOCK(buf.st_mode)){
        printf("s");
    }

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
    }else {
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

    printf(" ");

    printf("%4d ", buf.st_nlink);

    psd = getwuid(buf.st_uid);
    grp = getrgid(buf.st_gid);
    printf("%-8s", psd->pw_name);
    printf("%-8s", grp->gr_name);

    printf("%6d ", buf.st_size);

    printf("%s ",buf.st_mtime);
}
*/
void display_single()
{

}

char** get_files(const char* path)
{
    DIR* dir;
    struct dirent* ptr;
    struct dirent* ptrr;
    int j = 0;
    
    if(dir = opendir(path) == NULL)
    {
        perror("opendir");
        exit(1);
    }

    while((ptr = readdir(dir)) != NULL)
    {
        files_num ++;
    }

    char** files = (char**) malloc (sizeof(char*)*files_num);

    while((ptrr = readdir(dir)) != NULL)
    {
        files[j] = (char*) malloc (sizeof(char) * (ptrr->d_reclen));
        for(int i = 0; i<ptrr->d_reclen; i++)
        {
            file_num[i] = ptrr->d_reclen;
            files[j][i] = ptrr->d_name[i];
        }
    }

    return files;
}

void display_2(char** files)
{
    for(int i = 0; i < files_num; i++)
    {
        for(int j = 0; j < file_num[i]; j++)
        {
            printf("%c",files[i][j]);
        }
        printf("  ");
    }
}

void display_1(char** files)
{
    for(int i = 0; i < files_num; i++)
    {
        if(files[i][0] != '.')
        {   
            for(int j = 0; j < file_num[i]; j++)
            {
                printf("%c",files[i][j]);
            }
        printf("  ");
        }
    }
}
int main(int argc, char** argv)
{
    char path[100];
    char** files;
    strcpy(path,"./");
    files = get_files(path);
    display_1(files);
    printf("\n");
    printf("\n");
    display_2(files);

    return 0;
}