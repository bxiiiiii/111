#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int id;
	struct _node* next;
}Node;

typedef struct _list
{
	Node* head;
	Node* tail;
}List;

void creat(List* plist);
void dellast(List* plist);
void delk(List* plist);
void print(List* plist);

int main()
{
	List list;
	creat(&list);
	dellast(&list);
	delk(&list);
	
	return 0;
}

void print(List* plist)
{
	Node* q = plist->head->next;
	printf("内容为:\n");
	for (; q; q = q->next)
	{
		printf("id : %d\n", q->id);
	}
	printf("\n");
}

void creat(List* plist)
{
	Node* q = (Node*)malloc(sizeof(Node));
	plist->head = plist->tail = q;
	q->next = NULL;
	printf("输入-1停止\n");
	int n;
	do
	{
		scanf("%d", &n);
		if(n != -1)
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->id = n;
			p->next = NULL;
			plist->tail->next = p;
			plist->tail = p;
		}
	} while(n != -1);
	print(plist);
}

void dellast(List* plist)
{
	Node* q = plist->head->next;
	Node* p = plist->head;
	for ( ; q; q = q->next, p = p ->next)
	{
		if(q->next == NULL)
		{
			p->next = NULL;
			free(q);
			break;
		}
	}
	print(plist);
}

void delk(List* plist)
{
	int n;
	int ice = 0;
	Node* q = plist->head;
	Node* p = plist->head->next;
	printf("输入要删除的内容:");
	scanf("%d", &n);
	for (; p; q = q->next, p = p->next)
	{
		if(p->id == n)
		{
			ice = 1;
			q->next = p->next;
			free(p);
			break;
		}
	}
	if (ice) print(plist);
	else printf("No");
}
