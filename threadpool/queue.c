//
// Created by Administrator on 2020/1/2.
//

#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN_CAPCITY  10
queue_t* create_queue(int size)
{
    queue_t* queue= calloc(1, sizeof(queue_t));
    if(queue == NULL){
        exit(EXIT_FAILURE);
    }
    if(size <= 0){
        queue->capcity = MIN_CAPCITY;
    }else{
        queue->capcity = size;
    }
    queue->tasks = calloc(1, queue->capcity * sizeof(task_t));
    if(queue->tasks == NULL){
        exit(EXIT_FAILURE);
    }
    return queue;
}
bool queue_is_full(queue_t* queue)
{
    return queue->size == queue->capcity;
}
bool queue_is_empty(queue_t* queue)
{
    return queue->size == 0;
}
int queue_push_task(queue_t* queue, task_t* task)
{
    if(task == NULL){
        return -1;
    }
    if(queue->size == queue->capcity){
        return -2;
    }
    queue->tasks[queue->tail].run = task->run;
    queue->tasks[queue->tail].argv = task->argv;
//    queue->tasks[queue->tail] = task;
    queue->tail = (++queue->tail)%queue->capcity;
    queue->size++;
//    printf("size when file id:%d\n", (*(int*)(task->argv)));
    return 0;
}

task_t* queue_get_task(queue_t* queue)
{
    if(queue == NULL){
        return NULL;
    }
    if(queue->size == 0){
        return NULL;
    }
    task_t* task = &(queue->tasks[queue->head]);
    queue->head = (++queue->head)%queue->capcity;
    queue->size--;
//    printf("size when head:%d file_id:%d\n", queue->head, *((int*)(task->argv)));
    return task;
}
void queue_free(queue_t* queue)
{
    if(queue == NULL){
        return;
    }
    free(queue->tasks);
    free(queue);
}