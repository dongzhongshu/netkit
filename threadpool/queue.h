//
// Created by Administrator on 2020/1/2.
//

#ifndef NETKIT_QUEUE_H
#define NETKIT_QUEUE_H
#include <stdbool.h>
typedef struct queue_task{
    void* (*run)(void*);
    void* argv;
}task_t;
typedef struct _queue{
    int head;
    int tail;
    int capcity;
    int size;
    task_t *tasks;
}queue_t;

queue_t* create_queue(int size);
bool queue_is_full(queue_t*);
bool queue_is_empty(queue_t*);
int queue_push_task(queue_t* queue, task_t* task);
task_t* queue_get_task(queue_t*);
void queue_free(queue_t* q);
#endif //NETKIT_QUEUE_H
