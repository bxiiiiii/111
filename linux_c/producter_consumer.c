#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 5

typedef struct Node
{
	int ppp;
	struct Node* next;
}node;

int num;
node *head = NULL;
node *tail = NULL;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producter1()
{
	while(1)
	{
		if(num < MAX)
		{
			pthread_mutex_lock(&mutex);

			tail = (node *)malloc(sizeof(node));
			tail->ppp = rand() % 400; 
			tail->next = head;
			head = tail;
			num++;

			printf("producter1 : %d\n", tail->ppp);

			pthread_mutex_unlock(&mutex);

			pthread_cond_signal(&cond);

		}
		else printf("maxmax1\n");

		sleep(rand() % 2);
	}
}

void *producter2()
{
	while(1)
	{
		if(num < MAX)
		{
			pthread_mutex_lock(&mutex);

			tail = (node *)malloc(sizeof(node));
			tail->ppp = rand() % 400; 
			tail->next = head;
			head = tail;
			num++;

			printf("producter2 : %d\n", tail->ppp);

			pthread_mutex_unlock(&mutex);

			pthread_cond_signal(&cond);

		}
		else printf("maxmax2\n");
		sleep(rand() % 2);
	}
}

void *consumer1()
{
	while(1)
		{
			pthread_mutex_lock(&mutex);
			while(head == NULL)
				{
					printf("minmin1\n");
					pthread_cond_wait(&cond, &mutex);
				}
			tail = head;
			head = tail->next;

			printf("--------------------consumer1 : %d\n", tail->ppp);
			free(tail);
			tail = NULL;
			num--;

			pthread_mutex_unlock(&mutex);

			sleep(rand() % 3);
		}
}

void *consumer2()
{
	while(1)
		{
			pthread_mutex_lock(&mutex);
			while(head == NULL)
				{
					printf("minmin2\n");
					pthread_cond_wait(&cond, &mutex);
				}
			tail = head;
			head = tail->next;

			printf("-----------------------------------consumer2 : %d\n", tail->ppp);
			free(tail);
			tail = NULL;
			num--;

			pthread_mutex_unlock(&mutex);

			sleep(rand() % 3);
		}
}

int main()
{
	pthread_t tid1, tid2, tid3, tid4;
	pthread_create(&tid1, NULL, producter1, NULL);
	pthread_create(&tid2, NULL, producter2, NULL);
	pthread_create(&tid3, NULL, consumer1, NULL);
	pthread_create(&tid4, NULL, consumer2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	return 0;
}