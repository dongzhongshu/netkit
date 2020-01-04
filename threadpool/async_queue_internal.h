//
// Created by Administrator on 2020/1/2.
//

#ifndef NETKIT_ASYNC_QUEUE_INTERNAL_H
#define NETKIT_ASYNC_QUEUE_INTERNAL_H
#include "queue.h"
#include <pthread.h>
typedef struct async_queue{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int waiting_threads;
    queue_t* queue;
    int quit;
    int efd;
    int epollfd;
}async_queue_t;

typedef struct async_queue_op{
    const char* name;
    async_queue_t* (*create)(int size);
    int (*push)(async_queue_t* queue, task_t* task);
    task_t* (*pop)(async_queue_t* queue);
    void (*free)(async_queue_t* q);
    bool (*empty)(async_queue_t* q);
    int (*quit)(async_queue_t* q);
}async_queue_op_t;
#endif //NETKIT_ASYNC_QUEUE_INTERNAL_H
