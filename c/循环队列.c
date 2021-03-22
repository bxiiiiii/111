#include<stdio.h>

typedef struct queue
{
	int date[100];
	int head;
	int last;
}Queue;

Queue* initqueue(Queue* Q);
Queue* destoryqueue(Queue* Q);
Queue* Clearqueue(Queue* Q);
bool QueueEmpty(Queue* Q);
Queue* Gethead(Queue* Q);
Queue* Enqueue(Queue* Q);
Queue* Dequeue(Queue *Q);
int queuelength(Queue * Q);

int main()
{
	Queue Q;
	initqueue(&Q)
}

Queue* initqueue(Queue* Q)
{
	Q->head = Q->last = 0;
	return 1;
}

bool QueueEmpty(Queue* Q)
{
	if()
}

int queuelength(Queue * Q)
{
	
}

QueueQueue* destoryqueue(Queue* Q)
{
	
}
