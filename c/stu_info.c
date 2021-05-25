#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMEMAX 100

typedef struct student
{
    int num;
    char name[NAMEMAX];
    int grades;
    struct student* next;
}stu;

stu* Creat();
void Man();
void Sort(stu *arr);
void Print(stu *arr);
void Find(stu *arr);
void Free(stu *arr);

int main()
{
    int x;
	char ch;
    stu *arr;

    while(1)
    {
        Man();
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                arr = Creat();
                break;
            case 2:
                Sort(arr);
                break;
            case 3:
                Find(arr);
                break;
            case 4:
                Print(arr);
                break;
            case 5:
                Free(arr);
                exit(0);
			default:
				printf("输入错误，请输入正确序号！\n");
				continue;
        }

		printf("\n是否返回（y/n）:");
		scanf("%c", &ch);
		if(ch == 'y')
			continue;
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

stu* Creat()
{
    char Name[NAMEMAX];
    int N, Num, Grades;
    stu *p, *head, *tail;

    head = (stu *)malloc(sizeof(stu));
    head = NULL;
    tail = NULL;

    printf("学生个数：");
    scanf("%d", &N);
    while(N--)
    {
        printf("依次输入学号 姓名 成绩：");
        p = (stu *)malloc(sizeof(stu));
        scanf("%d %s %d", &Num, Name, &Grades);
        p->num = Num;
        strcpy(p->name, Name);
        p->grades = Grades;
        p->next = NULL;

        if(head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }

    return head;
}

void Sort(stu *arr)
{
    stu *p = arr->next;
    stu *q = arr;
    for( ; p->next != NULL; p = p->next);
    {
        if(p->num < q->num)
        {
           // p->next = 
        }
    }
}

void Find(stu *arr)
{
    int Num, ice;
    stu *p;

    printf("输入待查询的学生学号：");
    scanf("%d", &Num);
    ice = 0;
    p = arr;

    for( ; p; p = p->next)
            if(p->num == Num)
            {
                ice = 1;
                break;
            }
    if(ice) 
        printf("Num: %d\tName: %s\tGrades = %d\n", p->num, p->name, p->grades);
    else    
        printf("无\n");
}

void Print(stu *arr)
{
    stu *p = arr;
    printf("学号\t姓名\t成绩\n");
    for( ; p; p = p->next)
        printf("Num: %d\tName: %s\tGrades = %d\n", p->num, p->name, p->grades);
}

void Free(stu *arr)
{
    stu* q = arr;
	stu* p = NULL;
	for (; q; q = p)
	{
		p = q->next;
		free(q);
	}
	if (!q)
		printf("已退出\n");
}
