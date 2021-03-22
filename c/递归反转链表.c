#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int id;
	int value;
	struct _node* next;
}Node;
typedef struct _list
{
	Node* head;
	Node* tail;
}List;

void add(List* plist); 
void print(List* plist);
void reverse(List* plist);	
void rr(List* plist, Node* p, Node* q);

int main()
{
	List list;
	add(&list);
	print(&list);
	reverse(&list);
	print(&list);
	return 0;
}

void add(List* plist)
{
	printf("输入id为-1即停止输入\n");
	plist->head = plist->tail = NULL;
	int i, v;
	do
	{
		printf("请输入id:");
		scanf("%d", &i);
		if (i != -1)
		{
			printf("请输入value:");
			scanf("%d", &v);
			Node* p = (Node*)malloc(sizeof(Node));
			if (!p)
			{
				printf("False");
				exit(1);
			}
			p->id = i;
			p->value = v;
			p->next = NULL;
			if (plist->head)
			{
				plist->tail->next = p;
			}
			else
			{
				plist->head = p;
			}
			plist->tail = p;
		}
	} while (i != -1);
}

void print(List* plist)
{
	Node* q = plist->head;
	printf("id\tvalue\n");
	for (; q; q = q->next)
	{
		printf("%d\t%d\n", q->id, q->value);
	}
	printf("\n");
}

void reverse(List* plist)
{
	Node* q =plist->head->next;
	Node* p = NULL;
	rr(plist, p, q);
}

void rr(List* plist,Node* p, Node* q)
{
	plist->head->next = p;
	p = plist->head;
	plist->head = q;
	if(q) q = q->next;
	if(plist->head)
	{
		rr(plist, p, q);
	}
	else plist->head = p;
}

