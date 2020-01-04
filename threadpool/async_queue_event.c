//
// Created by Administrator on 2020/1/3.
//
#include "async_queue_internal.h"
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
static async_queue_t* queue_event_create(int size);
static int queue_event_push(async_queue_t* queue, task_t* task);
static task_t* queue_event_pop(async_queue_t* queue);
static void queue_event_free(async_queue_t* q);
static bool queue_event_empty(async_queue_t* q);
static int queue_event_quit(async_queue_t* q);

const async_queue_op_t g_async_queue_event_op={
        "event",
        queue_event_create,
        queue_event_push,
        queue_event_pop,
        queue_event_free,
        queue_event_empty,
        queue_event_quit
};


async_queue_t* queue_event_create(int size)
{
    async_queue_t* async_queue = calloc(1, sizeof(async_queue_t));
    assert(async_queue != NULL);
    pthread_mutex_init(&async_queue->mutex, NULL);
    pthread_cond_init(&async_queue->cond, NULL);
    async_queue->queue = create_queue(size);
    async_queue->epollfd = epoll_create1(0);
    assert(async_queue != NULL);
    return async_queue;
}

int queue_event_push(async_queue_t* asyncqueue, task_t* task)
{
    if(asyncqueue == NULL){
        return -1;
    }
    int ret = -1;
    unsigned long long i = 1;
    if(!queue_is_full(asyncqueue->queue) && asyncqueue->quit==0){
        queue_push_task(asyncqueue->queue, task);
        struct epoll_event ev;
        int efd = eventfd(0, EFD_CLOEXEC|EFD_NONBLOCK);
        if(efd != -1){
            ev.events = EPOLLIN;
            ev.data.fd = efd;
            if(epoll_ctl(asyncqueue->epollfd, EPOLL_CTL_ADD, efd, &ev) == -1){
                printf("epoll_ctl create error:%s", strerror(errno));
                return -1;
            }
            write(efd, &i, sizeof(i));
            ret = 0;
        }else{
            printf("eventfd create: %s\n", strerror(errno));
        }
    }
    return ret;
}

task_t* queue_event_pop(async_queue_t* asyncqueue)
{
    if(asyncqueue == NULL){
        return NULL;
    }
    unsigned long long i = 0;
    struct epoll_event events[1024];
    int nfds = epoll_wait(asyncqueue->epollfd, events, 1024, -1);
    if(nfds == -1){
        return NULL;
    }
    read(events[0].data.fd, &i, sizeof(i));
    close(events[0].data.fd);
    task_t* task = queue_get_task(asyncqueue->queue);
//    printf("get task file id:%d\n", (int)(*(int*)(task->argv)));
    return task;


}

void queue_event_free(async_queue_t* q)
{
    if(q == NULL){
        return;
    }
    if(q->epollfd > 0){
        close(q->epollfd);
    }
    queue_free(q->queue);
    pthread_cond_destroy(&q->cond);
    pthread_mutex_destroy(&q->mutex);
    free(q);
}


bool queue_event_empty(async_queue_t* q)
{
    return queue_is_empty(q->queue);
}


int queue_event_quit(async_queue_t* q)
{
    q->quit = 1;
    return 0;
}