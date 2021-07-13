#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct work_t
{
    void *arg;
    void *(*func)(void *);
    struct work_t *next;
}tp_w;

typedef struct threadpool_t
{
    int max_thr;
    int busy_thr;

//  pthread_t TTid;
    pthread_t *tids;
    tp_w *list, *tail;
    int type;

//    pthread_mutex_t tt;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}tp_t;

tp_t *tp_create(int max);
void tp_add(tp_t *pool, void *work, void *arg);
void tp_destory(tp_t *pool);
void *work(void *arg);
void *pool(void *arg);
//void *TT();
void my_error(const char *str, int line);

int main()
{
    int i;
    tp_t *tp = tp_create(10);

    for(i = 0; i < 5; i++)
    {
        printf("add task %d\n", i);
        tp_add(tp, work, NULL);
    }
    sleep(10);
    tp_destory(tp);
    return 0;
}

void my_error(const char *str, int line)
{
    fprintf(stderr, "line : %d \n", line);
    perror(str);
    exit(1);
}

tp_t* tp_create(int max)
{
    tp_t *tp = (tp_t *)malloc(sizeof(tp_t));
    if(!tp)
        my_error("malloc failed", __LINE__);

    tp->max_thr = max;
    tp->busy_thr = 0;
    tp->type = 1;
    tp->list = NULL;
    tp->tail = NULL;
   // pthread_mutex_init(&tp->tt, NULL);
    pthread_mutex_init(&tp->mutex, NULL);
    pthread_cond_init(&tp->cond, NULL);

    tp->tids = (pthread_t *)malloc(max * sizeof(pthread_t));
    if(!tp->tids)
        my_error("malloc failed", __LINE__);
    for(int i = 0; i < max; i++)
        pthread_create(&tp->tids[i], NULL, pool, (void *)tp);

    return tp;
}

void tp_destory(tp_t *pool)
{
    pthread_mutex_lock(&pool->mutex);
    pool->type = 0;
    pthread_cond_broadcast(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);
    for (int i = 0; i < pool->max_thr; i++)
        pthread_join(pool->tids[i], NULL);
    while (pool->list)
    {
        pool->tail = pool->list->next;
        free(pool->list);
        pool->list = pool->tail;
    }
    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    free(pool);
    printf("Free success.\n");
}

void tp_add(tp_t *pool, void *work, void *arg)
{
    tp_w *Work = (tp_w *)malloc(sizeof(tp_w));
    if(!Work)
        my_error("malloc failed", __LINE__);

    Work->func = work;
    Work->arg = arg;
    Work->next = NULL;

    pthread_mutex_lock(&pool->mutex);

    if(pool->list)
        pool->tail->next = Work;
    else
        pool->list = Work;

    pool->tail = Work;

    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);
}

void *work(void *arg)
{
    printf("thread %ld is working.\n", pthread_self());
    sleep(5);
    printf("thread %ld has done.\n", pthread_self());
}

void *pool(void *arg)
{
    tp_t *pool = (tp_t *)arg;
    tp_w *task;

    while(1)
    {
        if(!pool->type)
        {
            printf("thread %ld is exiting.\n", pthread_self());
            pthread_exit(NULL);
        }
        pthread_mutex_lock(&pool->mutex);
        while((!pool->list))
        {
            if(!pool->type)
            {
                printf("thread %ld is exiting.\n", pthread_self());
                pthread_mutex_unlock(&pool->mutex);
                pthread_exit(NULL);
            }
            printf("thread %ld is waiting.\n", pthread_self());
            pthread_cond_wait(&pool->cond, &pool->mutex);
        }

        task = pool->list;
        pool->list = pool->list->next;
        pthread_mutex_unlock(&pool->mutex);
        task->func(task->arg);
        free(pool);
    }
}