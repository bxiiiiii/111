#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int id;
	struct _node *fnext;
	struct _list *lnext;
}Node;

typedef struct _list
{
	Node* head;
	Node* tail;
}List;

void creat(List *plist);
void del(List* plist);
void print(List* plist);
void cut(List* plist);

int main()
{
	List list;
	creat(&list);
	print(&list);
	del(&list);
	cut(&list);

	return 0;
}

void creat(List *plist)
{
	Node* q = (Node*)malloc(sizeof(Node));
	plist->head = plist->tail = q;
	q->fnext = NULL;
	int i;
	printf("输入-1停止:\n");
	do
	{
		scanf("%d",&i);
		if(i != -1)
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->id = i;
			p->fnext = plist->tail;
			p->lnext = NULL;
			plist->tail->lnext = p;
			plist->tail = p;
		}
	}while(i != -1);
	
}

void print(List* plist)
{
	Node* p = plist->head->fnext;
	printf("内容为:\n");
	for ( ; p; p = p->fnext)
	{
		printf("%d\n", p->id);
	}
	printf("\n");
}

void del(List* plist)
{
	int i, ice = 0;
	Node* p = plist->head->fnext;
	Node* q = plist->head;
	printf("输入删除内容:");
	scanf("%d", &i);
	for (; p; q = p, p = p->fnext)
	{
		if(p->id == i)
		{
			q->lnext = p->lnext;
			p->lnext->fnext = q;
			free(p);
			break;
		}
	}
	if(ice) print(plist);
	else printf("NO\n");
}

void cut(List* plist)
{
	printf("111");
	Node* q = plist->head->fnext;
	for (; q; )
	{
		plist->head->fnext = q->fnext;
		free(q);
		q = plist->head->fnext;
	}
	if(plist->head->fnext == NULL) printf("yes\n");
	else printf("No\n");
}












