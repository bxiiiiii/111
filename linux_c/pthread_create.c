#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int* thread()
{
    pthread_t newthid;

    newthid = pthread_self();
    printf("new thread, id is %lu\n", newthid);
    return NULL;
}

int main()
{
    pthread_t thid;

    printf("main thread, id is %lu\n", pthread_self());
    if(pthread_create(&thid, NULL, (void*)thread, NULL) != 0)
    {
        perror("thread creation failed\n");
        exit(1);
    }
    sleep(1);
    exit(0);
}