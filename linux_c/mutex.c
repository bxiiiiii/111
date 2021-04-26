#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *tfn(void *arg)
{
	srand(time(NULL));

	while(1){
		pthread_mutex_lock(&mutex);
		printf("hello ");
		sleep(rand() % 3);
		printf("world\n");

		pthread_mutex_unlock(&mutex);

		sleep(rand() % 3);
	}

	return NULL;
}

int main()
{
	
	pthread_t tid;
	srand(time(NULL));

	int ret = pthread_mutex_init(&mutex, NULL);
	if(ret != 0)
		exit(1);

	pthread_create(&tid, NULL, tfn, NULL);
	while(1){
		pthread_mutex_lock(&mutex);
		printf("HELLO ");
		sleep(rand() % 3);
		printf("WORLD\n");

		pthread_mutex_unlock(&mutex);

		sleep(rand() % 3);
	}
pthread_join(tid, NULL);

pthread_mutex_destroy(&mutex);

	return 0;
}
