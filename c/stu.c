#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMEMAX 100

typedef struct student
{
    int num;
    char name[NAMEMAX];
    int grades;
}stu;

stu** Creat(int *n);
void Man();
void Sort(stu *arr[], int N);
void Print(stu *arr[], int N);
void Find(stu *arr[], int N);

int main()
{
    int x, n = 0;
	char ch;
    stu **arr;

    while(1)
    {
        Man();
        printf("输入对应序号：");
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                arr = Creat(&n);
                break;
            case 2:
                Sort(arr, n);
                break;
            case 3:
                Find(arr, n);
                break;
            case 4:
                Print(arr, n);
                break;
            case 5:
                printf("已退出\n");
                exit(0);
			default:
				printf("输入错误，请输入正确序号！\n");
				continue;
        }

        printf("是否返回（y/n）：");
        scanf("%s", &ch);
    }

    return 0;
}

void Man()
{
	printf("\n------------------\n");
    printf("1.学生信息录入\n");
    printf("2.成绩排序\n");
    printf("3.学生信息查询\n");
    printf("4.学生信息查看\n");
    printf("5.退出\n");
    printf("------------------\n");
}

stu** Creat(int *n)
{
    char Name[NAMEMAX];
    int N, Num, Grades;

    stu **head;
    stu *p;

    printf("学生个数：");
    scanf("%d", &N);
    *n = N;

    head = (stu **)malloc(sizeof(stu)*N);
    for(int i = 0; i < N; i++)
    {
        printf("依次输入学号 姓名 成绩：");
        p = (stu *)malloc(sizeof(stu));
        scanf("%d %s %d", &Num, Name, &Grades);
        p->num = Num;
        strcpy(p->name, Name);
        p->grades = Grades;

        head[i] = p;
    }

    return head;
}

void Sort(stu *arr[], int N)
{
    if(!N)
    {
        printf("无数据\n");
        return ;
    }

    int i, j;

    for(i = N; i > 0; i--)
    {
        for(j = 1; j < i; j++)
        {
            if(arr[j-1]->grades > arr[j]->grades)
            {
                stu *temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    printf("已排序\n");
}

void Find(stu *arr[], int N)
{
    if(!N)
    {
        printf("无数据\n");
        return ;
    }

    int Num, ice, i;

    printf("输入待查询的学生学号：");
    scanf("%d", &Num);
    ice = 0;

    for(i = 0; i < N; i++)
            if(arr[i]->num == Num)
            {
                ice = 1;
                break;
            }
    if(ice) 
        printf("Num: %d\tName: %s\tGrades = %d\n", arr[i]->num, arr[i]->name, arr[i]->grades);
    else    
        printf("无\n");
}

void Print(stu *arr[], int N)
{
    if(!N)
        {
            printf("无数据\n");
            return ;
        }

    printf("学号\t姓名\t成绩\n");
    for(int i = 0; i < N; i++)
        printf("Num: %d\tName: %s\tGrades = %d\n", arr[i]->num, arr[i]->name, arr[i]->grades);
}
