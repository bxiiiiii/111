#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <dirent.h>
 
#define nomal 0
#define out 1
#define in 2
#define pipee 3
#define outout 4

void prompt();
void get_param(char* param);
int find(char* param);
void cd(char *path);
void anal(char* param, int* num, char arr[100][256]);
void exec(int param_num, char para[100][256]);
 
int main(int argc, char* argv[])
{

    signal(SIGINT, SIG_IGN);

    while(1)
    {
        int param_num = 0;
		char *param = (char*) malloc (256);
        char param_arr[100][256];
        
		prompt();
        get_param(param);

        if((strcmp("exit", param) == 0 ) || (strcmp("logout", param) == 0))
            break;

        anal(param, &param_num, param_arr);

        if(strcmp(param_arr[0],"cd") == 0)
        {
            cd(param_arr[1]);
            continue;
        }

        exec(param_num, param_arr);
        
        free(param);
    }
    return 0;
}

void prompt()
{
	char hostname[500];
    char buf[500];
	struct passwd* id;
    uid_t uid;

	uid = geteuid();
    id = getpwuid(uid);

	gethostname(hostname, 500);
    getcwd(buf, 500);

    printf("\033[32m%s@%s\033[0m:\033[34m%s\033[0m$ ", id->pw_name, hostname, buf);
}

void get_param(char* param)
{
    char ch;
    int i = 0;
    do{
        ch = getchar();
        if(ch == '\n') break;
        param[i++] = ch;
    }while (1);
    param[i] = '\0';
}

void anal(char* param, int* num, char arr[100][256])
{
    char* p = param;
    char* q = param;
    int number = 0;
    while(1)
    {
        if(p[0]=='\0')
        break;
        if(p[0]==' ')
        p++;
        else
        {
            q=p;
            number=0;
            while(q[0]!='\0' && q[0]!=' '){
                q++;
                number++;
            }
            strncpy(arr[*num],p,number+1);
            arr[*num][number]='\0';
            *num = *num+1;
            p=q;
        }
    }

}

void exec(int param_num, char para[100][256])
{
    pid_t pid;
    pid_t pid2;
    int fd;
    int stat_val;
	int stat_val2;
    int i, x = 0;
    int flag = 0;
    int how = 0;
    int bg = 0;
    char* file;
    char* arg[param_num+1];
    char* arg1[param_num+1];

    for(i = 0; i < param_num; i++)
    {
        arg[i] = (char*)para[i];
    }
    arg[param_num]=NULL;


    if(!find(arg[0])) return;

    for(i = 0; i < param_num; i++)
    {
        if(strcmp(arg[i], "<") == 0)
        {
            flag++;
            how = in;
        }
        if(strcmp(arg[i], ">" )== 0)
        {
            flag++;
            how = out;
        }
        if(strcmp(arg[i], "|") == 0)
        {
            flag++;
            how = pipee;
        }
		if(strcmp(arg[i], "&") == 0)
		{
			bg = 1;
		}
        if(strcmp(arg[i], ">>") == 0)
        {
            flag++;
            how = outout;
        }
    }

    if(flag > 1)
    {
        printf("param_num limit\n");
        exit(1);
    }

    if(how == out)
    {
        for(i = 0; i < param_num; i++)
        {
            if(strcmp(para[i], ">") == 0)
            {
                arg[i] = NULL;
                file = arg[i+1];
                break;
            }
        }
    }

    if(how == in)
    {
        for(i = 0; i < param_num; i++)
        {
            if(strcmp(para[i], "<") == 0)
            {
                arg[i] = NULL;
                file = arg[i+1];
                break;
            }
        }
    }
    
    if(how == pipee)
    {
        for(i = 0; i < param_num; i++)
        {
            if(strcmp(para[i], "|") == 0)
            {
                arg[i] = NULL;
                for(int j = i+1; j < param_num; j++, x++)
                {
                    arg1[x] = para[j];
                }
                arg1[x+1] = NULL;
                break;
            }
        }
    }

    if(how == outout)
    {
        for(i = 0; i < param_num; i++)
        {
            if(strcmp(para[i], ">>") == 0)
            {
                arg[i] = NULL;
                file = arg[i+1];
                break;
            }
        }
    }

    if((pid = vfork()) == -1)
    {
        printf("process creation failed\n");
        exit(1);
    }

    switch (how){
        case 0:
            if(pid == 0)
            {
                execvp(arg[0], arg);
                exit(0);
            }
            break;
        case 1:
            if(pid == 0)
            {
                fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
                dup2(fd, 1);
                execvp(arg[0], arg);
                exit(0);
            }
            break;
        case 2:
            if(pid == 0)
            {
                fd = open(file, O_RDONLY);
                dup2(fd, 0);
                execvp(arg[0], arg);
                exit(0);
            }
            break;
        case 3:
            if(pid == 0)
            {
                pid2 = vfork();
                if(pid2 == 0)
                {
                    fd = open("./trans", O_RDWR | O_CREAT | O_TRUNC, 0777);
                    dup2(fd, 1);
                    execvp(arg[0], arg);
                    exit(0);
                }
                else
                {
					waitpid(pid2, &stat_val, 0);
                    fd = open("./trans", O_RDONLY);
                    dup2(fd, 0);
                    execvp(arg1[0], arg1);
                    exit(0);
                }
            }
            break;
        case 4:
            if(pid == 0)
            {
                fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
                dup2(fd, 1);
                execvp(arg[0], arg);
                exit(0);
            }
            break;
        default:
            break;
    }

	if(bg) return;

    waitpid(pid, &stat_val, 0);
}

int find(char* param)
{
    DIR* dir;
    struct dirent* ptr;
    int ice = 0;
    dir = opendir("/bin");
    while(ptr = readdir(dir))
    {
        if(strcmp(param, ptr->d_name) == 0)
            return 1;
    }
    closedir(dir);
    dir = opendir("/home/bx/桌面/ccc/bxx/linux_c");
    while(ptr = readdir(dir))
    {
        if(strcmp(param, ptr->d_name) == 0)
            return 1;
    }
    closedir(dir);
    printf("Command '%s' not found\n", param);
    return 0;
}
void cd(char *path)
{
    if(chdir(path) < 0)
        perror("chdir");
}
