//
// Created by Administrator on 2020/1/2.
//
#include "async_queue_internal.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
static async_queue_t* queue_cond_create(int size);
static int queue_cond_push(async_queue_t* queue, task_t* task);
static task_t* queue_cond_pop(async_queue_t* queue);
static void queue_cond_free(async_queue_t* q);
static bool queue_cond_empty(async_queue_t* q);
static int queue_cond_quit(async_queue_t* q);

const async_queue_op_t g_async_queue_cond_op={
        "cond",
        queue_cond_create,
        queue_cond_push,
        queue_cond_pop,
        queue_cond_free,
        queue_cond_empty,
        queue_cond_quit
};


async_queue_t* queue_cond_create(int size)
{
    async_queue_t* async_queue = calloc(1, sizeof(async_queue_t));
    assert(async_queue != NULL);
    pthread_mutex_init(&async_queue->mutex, NULL);
    pthread_cond_init(&async_queue->cond, NULL);
    async_queue->queue = create_queue(size);
    assert(async_queue != NULL);
    return async_queue;
}

int queue_cond_push(async_queue_t* asyncqueue, task_t* task)
{
    if(asyncqueue == NULL){
        return -1;
    }
    int ret = -1;
    pthread_mutex_lock(&asyncqueue->mutex);
    if(!queue_is_full(asyncqueue->queue) && asyncqueue->quit==0){
        queue_push_task(asyncqueue->queue, task);
        pthread_cond_signal(&asyncqueue->cond);
        ret = 0;
    }
    pthread_mutex_unlock(&asyncqueue->mutex);
    return ret;
}

task_t* queue_cond_pop(async_queue_t* asyncqueue)
{
    if(asyncqueue == NULL){
        return NULL;
    }
    pthread_mutex_lock(&asyncqueue->mutex);
    asyncqueue->waiting_threads++;
    while(queue_is_empty(asyncqueue->queue) && asyncqueue->quit==0){
        pthread_cond_wait(&asyncqueue->cond, &asyncqueue->mutex);
    }
//    printf("get task...\n");
    asyncqueue->waiting_threads--;
    task_t* task = queue_get_task(asyncqueue->queue);
//    printf("get task file id:%d\n", (int)(*(int*)(task->argv)));
    pthread_mutex_unlock(&asyncqueue->mutex);
    return task;


}

void queue_cond_free(async_queue_t* q)
{
    if(q == NULL){
        return;
    }
    queue_free(q->queue);
    pthread_cond_destroy(&q->cond);
    pthread_mutex_destroy(&q->mutex);
    free(q);
}


bool queue_cond_empty(async_queue_t* q)
{
    return queue_is_empty(q->queue);
}


int queue_cond_quit(async_queue_t* q)
{
    pthread_mutex_lock(&q->mutex);
    q->quit = 1;
    pthread_cond_broadcast(&q->cond);
    pthread_mutex_unlock(&q->mutex);
    return 0;
}