//
// Created by Administrator on 2020/1/2.
//

#include "thread_pool.h"
#include "async_queue_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern const async_queue_op_t g_async_queue_cond_op;
extern const async_queue_op_t g_async_queue_event_op;
static const async_queue_op_t* async_queue_ops[] =
{
        &g_async_queue_cond_op,
        &g_async_queue_event_op
};
static threadpool_type_t threadpool_current = threadpool_cond_type;

static void* threadpool_thread(void *threadpool);

int threadpool_free(threadpool_t *pool);

bool threadpool_config(threadpool_type_t type)
{
    threadpool_current = type;
    return true;
}

threadpool_t* threadpool_create(int thread_count, int queue_size, int flags)
{
    threadpool_t* pool;
    if ((thread_count <=0) || (thread_count > MAX_THREAD_POOL_SIZE) || (queue_size <=0) || (queue_size > MAX_QUEUE_SIZE))
    {
        printf("please check your input parameters.\n");
        return NULL;
    }
    if ((pool = (threadpool_t*)calloc(1, sizeof(threadpool_t))) == NULL)
    {
        printf("malloc threadpool memory failed.\n");
        return NULL;
    }
    pool->qsize = queue_size;
    pool->tsize = thread_count;
    pool->qop  = async_queue_ops[threadpool_current];
    pool->threads = (pthread_t*)calloc(1, thread_count * sizeof(pthread_t));
    pool->started = false;
    pool->queue = pool->qop->create(queue_size);
    for(int i=0; i<pool->tsize; i++){
        if(pthread_create(&pool->threads[i], NULL, threadpool_thread, (void*)pool) != 0){
            printf("create thread failed.\n");
            threadpool_destroy(pool, 0);
            return NULL;
        }
    }
    pool->started = true;
    return pool;
}

int threadpool_add(threadpool_t *pool, void* (*routine)(void *), void *arg)
{
    int err = 0;

    if(pool == NULL || routine == NULL)
    {
        return threadpool_invalid;
    }

    do{
        if(pool->shutdown){
            err = 1;
            break;
        }
        task_t task;
        task.run  = routine;
        task.argv = arg;
//        printf("will push task...\n");
        if (pool->qop->push(pool->queue, &task) < 0)
        {
            printf("push task to queue failed.\n");
        }
    }while(0);
    return err;
}

int threadpool_destroy(threadpool_t *pool, int flags)
{
    int i, err = 0;

    if(pool == NULL)
    {
        return threadpool_invalid;
    }

    do {
        /* Already shutting down */
        if(pool->shutdown)
        {
            err = threadpool_shutdown;
            break;
        }

        pool->shutdown = (flags & threadpool_graceful) ?
                         graceful_shutdown : immediate_shutdown;

        /* Destory all worker threads */
//        if(pool->shutdown == immediate_shutdown){

            pool->qop->quit(pool->queue);
//        }
        /* Join all worker thread */
        for(i = 0; i < pool->tsize; i++)
        {
            if(pthread_join(pool->threads[i], NULL) != 0)
            {
                err = threadpool_thread_failure;
            }
        }
    } while(0);

    /* Only if everything went well do we deallocate the pool */
    if(!err)
    {
        threadpool_free(pool);
    }

    return err;
}

int threadpool_free(threadpool_t *pool)
{
    if(pool == NULL || pool->started > 0)
    {
        return -1;
    }

    if(pool->threads)
    {
        free(pool->threads);
        pool->qop->free(pool->queue);
    }
    free(pool);

    return 0;
}

void* threadpool_thread(void *threadpool)
{
    threadpool_t* pool = (threadpool_t*)threadpool;
//    printf("enter threadpool_thread...\n");
    while(true){
        task_t* task = pool->qop->pop(pool->queue);
        if(task != NULL){
//            printf("will run task...\n");
            task->run(task->argv);
        }
        if(pool->shutdown == immediate_shutdown){
            threadpool_destroy(pool, immediate_shutdown);
            break;
        }else if(pool->shutdown == graceful_shutdown){
            if(!pool->qop->empty(pool->queue)){
                printf("waiting for shutdown...\n");
                continue;
            }
            threadpool_destroy(pool, graceful_shutdown);
            break;
        }
    }
    return NULL;
}