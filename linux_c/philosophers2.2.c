#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include<semaphore.h>

sem_t sem[5];

void *eat_or_think(void *arg)
{
    int id = *(int *)arg;

    if(id&1)
    {
		sem_wait(&sem[id-1]); 
        printf("%d get left(%d)\n", id, id-1);
		sem_wait(&sem[id%5]);
        printf("-----------%d is eating(%d)\n",id, id%5);
    }		
    else
    {
        sem_wait(&sem[id%5]); 
        printf("%d get right(%d)\n", id, id%5);
		sem_wait(&sem[id-1]);
        printf("-----------%d is eating(%d)\n",id, id-1);
    }
        
		sleep(5); //吃饭
		sem_post(&sem[id-1]);	//第i个哲学家放下左边筷子
		sem_post(&sem[id%5]);	//放下右边筷子
        printf("********************%d ate(%d)\n",id, id%5);
}

int main()
{
    pthread_t tid1, tid2, tid3, tid4, tid5;
    int a = 1, b = 2, c = 3, d = 4, e = 5;

        for(int i = 0; i < 5; i++)
	        sem_init(&sem[i], 0, 1); 

    pthread_create(&tid1, NULL, eat_or_think, (void *)&a);
    pthread_create(&tid2, NULL, eat_or_think, (void *)&b);
    pthread_create(&tid3, NULL, eat_or_think, (void *)&c);
    pthread_create(&tid4, NULL, eat_or_think, (void *)&d);
    pthread_create(&tid5, NULL, eat_or_think, (void *)&e);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_join(tid5,NULL);

    for(int i = 0; i < 5; i++)
            sem_destroy(&sem[i]);

    return 0;
}