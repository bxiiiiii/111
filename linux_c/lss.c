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
#include <signal.h>

#define _NONE 0
#define _A 1
#define _L 2
#define MAX 1000
#define MAXROWLEN 80

int g_leave_len = MAXROWLEN;
int filename_max;
int _R = 0;

void my_err(const char* err_string, int line); 
void display(int flag_param, char* filename);
void display_attribute(struct stat buf, char * name, char* filename);
void display_dir(int flag_param, char* path);
void display_1(char* name, char* filename);
void display_r(int flag_praram, char* filename);
void quicksort(char **a, int left, int right);
int getmid(int left,int right, char **a);
int get_color(char* filename);
void swap(char** a, int i, int j);

int main(int argc, char** argv)
{
    char path[MAX];
    char param[32];
    int flag_param = _NONE;
    int i, k, j = 0, num = 0;
    struct stat buf;

    signal(SIGINT, SIG_IGN);

    for(i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            for( k = 1; k < strlen(argv[i]); k++, j++)
            {
                param[j] = argv[i][k];
            }
            num++;
        }
    }

    for(i = 0; i < j; i++)
    {
        if(param[i] == 'a')
        {
            flag_param |= _A;
            continue;
        }else if(param[i] == 'l')
        {
            flag_param |= _L;
            continue;
        }else if(param[i] == 'R')
        {
            _R = 1;
            continue;
        }else
        {
            printf("my_ls:invaild option -%c\n", param[i]);
            exit(1);
        }
    }


    if(argc == (num+1))
    {
        strcpy(path,"./");
        path[2] = '\0';
        display_dir(flag_param, path);
        return 0;
    }

    i = 1;
    do{
        if(argv[i][0] == '-') 
        {
            i++;
            continue;
        }
        else
        {
            strcpy(path, argv[i]);
            if(stat(path, &buf) == -1) my_err("stat", __LINE__);

            if(S_ISDIR(buf.st_mode))
            {
                if(path[strlen(argv[i])-1] != '/')
                {
                    path[strlen(argv[i])] = '/';
                    path[strlen(argv[i])+1] = '\0';
                }
                else path[strlen(argv[i])] = '\0';
                display_dir(flag_param, path);
                i++;
            }
            else
            {
                display(flag_param, path);
                i++;
            }
        }
    }while(i<argc);

    return 0;
}

void display_r(int flag_param,char* filename)
{
    struct stat buf;
    lstat(filename, &buf);

    if(S_ISDIR(buf.st_mode))
    {
        int i, j = 0;
        char name[MAX];
        for(i = 0; i < strlen(filename); i++)
        {
            if(filename[i] == '/')
            {
                j = 0;
                continue;
            }
            name[j++] = filename[i];
        }
        name[j] = '\0';
        
        switch (flag_param){
            case _NONE :
                if(name[0] != '.') display_dir(flag_param,filename);
                break;
            case _A :
                display_dir(flag_param, filename);
                break;
            case _L+_A :
                display_dir(flag_param, filename);
                break;
            case _L :
                if(name[0] != '.') display_dir(flag_param,filename);
            default :
                break;
        } 
    }
    else free(filename);
}

void display(int flag_param, char* filename)
{
    struct stat buf;
    char name[MAX];
    int i, j;

    for(i = 0, j = 0; i < strlen(filename); i++)
    {
        if(filename[i] == '/')
        {
            j = 0;
            continue;
        }
        name[j++] = filename[i];
    }
    name[j] = '\0';


    if(lstat(filename, &buf) == -1) my_err("stat", __LINE__);

    switch (flag_param){
        case _NONE :
            if(name[0] != '.') display_1(name, filename);
            break;
        case _A :
            display_1(name, filename);
            break;
        case _L :
            if(name[0] != '.') display_attribute(buf, name, filename);
            break;
        case _L+_A :
            display_attribute(buf, name, filename);
            break;
        default :
            break;
    }   
}

void display_dir(int flag_param, char* path)
{
    DIR* dir;
    char temp[MAX] ;
    struct dirent* ptr;
    int filesnum = 0;
    int len = strlen(path);
    filename_max = 0;

    dir = opendir(path);

    if(dir == NULL)
    {
        fprintf(stderr, "lss: %s :", path);
        perror("opendir");
    }
    else{
        while((ptr = readdir(dir)) != NULL) 
        {
            if(filename_max < strlen(ptr->d_name)) 
            filename_max = strlen(ptr->d_name);
            filesnum ++;
        }
        closedir(dir);

        char **filenames = (char**)malloc(sizeof(char*)*filesnum);

        dir = opendir(path);
        for(int i = 0; i < filesnum; i++)
        {
            ptr = readdir(dir);
            if(ptr == NULL) my_err("readdir",__LINE__);
            filenames[i] = (char*)malloc(sizeof(char)*MAX);
            strncpy(filenames[i], path, len);
            if(filenames[i][len-1] != '/')
            {
                filenames[i][len] = '/';
                filenames[i][len+1] = '\0';
                strcat(filenames[i],ptr->d_name);
                filenames[i][len+strlen(ptr->d_name)+1] = '\0';
            }
            else 
            {
                filenames[i][len] = '\0';
                strcat(filenames[i], ptr->d_name);
                filenames[i][len+strlen(ptr->d_name)] = '\0';
            }
        }

        quicksort(filenames, 0, filesnum-1);

        if(_R)
        {
            printf("\n%s :\n", path);
        }
        
        for(int i = 0; i < filesnum; i++)
            display(flag_param,filenames[i]);
        printf("\n");
        closedir(dir);

        if(_R){
            for(int i = 2; i < filesnum; i++)
            {       
                    display_r(flag_param, filenames[i]);
            }
        }
    }
}

void display_1(char* name, char* filename)
{
    int i, len;
    if(g_leave_len < filename_max)
    {
        printf("\n");
        g_leave_len = MAXROWLEN;
    }

    int color = get_color(filename);
    printf("\033[%dm%s\033[0m", color, name);

    len = filename_max - strlen(name);
    for(i = 0; i < len; i++)
    {
        printf(" ");
    }
    printf("  ");
    g_leave_len -= (filename_max+2);

    //if(_R == 0) free(filename);

}

void display_attribute(struct stat buf, char * name, char* filename)
{
    char buf_time[32];
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

    printf("%4ld ", buf.st_nlink);

    psd = getpwuid(buf.st_uid);
    grp = getgrgid(buf.st_gid);

    printf("%-6s", psd->pw_name);

    printf("%-6s", grp->gr_name);

    printf("%6ld ", buf.st_size);

    strcpy(buf_time, ctime(&buf.st_mtime));
    buf_time[strlen(ctime(&buf.st_mtime))-1] = '\0';
    printf("%s  ", buf_time);


    int color = get_color(filename);
    printf("\033[%dm%s\033[0m", color, name);

    printf("\n");

    //if(_R == 0) free(filename);
}

void my_err(const char* err_string, int line)
{
    fprintf(stderr, "line : %d ", line);
    perror(err_string);
    exit(1);
}

int get_color(char* filename)
{
    struct stat buf;
    int color;

    if(lstat(filename, &buf) == -1) my_err("stat", __LINE__);

    if(S_ISDIR(buf.st_mode))
        color = 34;
    else if(S_ISLNK(buf.st_mode)){
        color = 36;
    }else if(S_ISCHR(buf.st_mode)){
        color = 33;
    }else if(S_ISBLK(buf.st_mode)){
        color = 33;
    }else if(S_ISFIFO(buf.st_mode)){
        color = 35;
    }else if(S_ISSOCK(buf.st_mode)){
        color = 35;
    }else if((buf.st_mode & S_IXOTH) || (buf.st_mode & S_IXUSR) || (buf.st_mode & S_IXGRP)){
        color = 32;
    }else if(S_ISREG(buf.st_mode)){
        color = 37;
    }
    return color;
}


void quicksort(char **a, int left, int right)
{     
    if(left < right)
    {
        int get = getmid(left, right, a);
        quicksort(a, left, get-1);
        quicksort(a, get+1, right);
    }
}

int getmid(int left,int right, char **a)
{
    char get[MAX];
    strcpy(get, a[right]);
    while(left < right)
    {   
        while(left<right &&  (strcmp(a[left], get) <= 0))
            left++;
        swap(a, right, left);   
        while(left<right && (strcmp(a[right], get) >= 0))
            right--;
        swap(a, left, right);
    }
    strcpy(a[left], get);
    return right;
}

void swap(char** a, int i, int j)
{
    char tem[MAX];
    strcpy(tem, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], tem);
}