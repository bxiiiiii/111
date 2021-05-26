#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t chopstick[5] ;

void *eat_or_think(void *arg)
{
    int id = *(int *)arg;

    if(id&1)
    {
   		pthread_mutex_lock(&chopstick[id-1]); 	
        printf("%d get left(%d)\n", id, id-1);
		pthread_mutex_lock(&chopstick[id%5]);	
        printf("-----------%d is eating(%d)\n",id, id%5);
    }
    else
    {
        pthread_mutex_lock(&chopstick[id%5]); 
        printf("%d get right(%d)\n", id, id%5);
		pthread_mutex_lock(&chopstick[id-1]);	
        printf("-----------%d is eating(%d)\n",id, id-1);
    }
		sleep(5); //吃饭
		pthread_mutex_unlock(&chopstick[id-1]);	//放下左边筷子
		pthread_mutex_unlock(&chopstick[id%5]);	//放下右边筷子
        printf("********************%d ate\n",id);
}

int main()
{
    pthread_t tid1, tid2, tid3, tid4, tid5;
    int a = 1, b = 2, c = 3, d = 4, e = 5;

    for (int i = 0; i < 5; i++)
       pthread_mutex_init(&chopstick[i],NULL); 

    
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

    return 0;
}