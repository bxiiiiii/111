#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

struct val{
    int var;
    char arr[256];
};

void *ff(void* arg)
{
    struct val *rel;
    rel = malloc(sizeof(struct val));
    rel->var = 200;
    strcpy(rel->arr,"hello");

    return (void *)rel;
}

void my_error(const char *str)
{
    perror(str);
    exit(1);
}

int main()
{
    pthread_t tid;
    struct val* rel;

    if(pthread_create(&tid, NULL, ff, NULL) != 0)
        my_error("pthread_create error");

    if(pthread_join(tid, (void *)&rel) != 0) 
        my_error("pthread_join error");

    printf("child thread exit with var = %d, arr = %s\n", rel->var, rel->arr);

    pthread_exit(NULL);
}