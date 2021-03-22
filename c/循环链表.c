#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int id;
	struct _node *next;
}Node;

typedef struct _list
{
	Node* head;
	Node* tail;
}List;

void creat(List* plist)
{
	Node* q = (Node*)malloc(sizeof(Node));
	plist->tail = plist->head = q;
	printf("输入-1停止\n");
	int i;
	do
	{
		scanf("%d", &i);
		if (i != -1)
		{
			q = (Node*)malloc(sizeof(Node));
			q->id = i;
			q->next = plist->head;
			plist->tail->next = q;
			plist->tail = q;
		}
	}while(i != -1);
}

void print(List* plist)
{
	Node* q = plist->head->next;
	for ( ; q != plist->head; q = q->next)
	{
		printf("id = %d\n", q->id);
	}
	printf("\n");
}

void del(List* plist)
{
	Node* q = plist->head->next;
	Node* p = plist->head;
	int i, ice = 0;
	printf("输入删除内容:");
	scanf("%d", &i);
	for ( ; q != plist->head; q = q->next, p = p->next)
	{
		if(q->id == i)
		{
			ice = 1;
			p->next = q->next;
			free(q);
			break;
		}
	}
	if (ice) print(plist);
	else printf("NO\n");
}

void _free(List* plist)
{
	Node* p = plist->head->next;
	Node* q = plist->head;
	for (; p != plist->head;p = q)
	{
		q = p->next;
		free(p);
	}
	plist->head->next = NULL;
}
int main()
{
	List list;
	creat(&list);
	print(&list);
	del(&list);
	_free(&list);

	return 0;
}







