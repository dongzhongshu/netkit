//
// Created by Administrator on 2020/1/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#include "ringbuffer.h"

#define	  FIFO_SIZE	16


void * consumer_proc(void *arg)
{
    unsigned int cnt;
    RingBuffer *ring_buf = (RingBuffer *)arg;

    cnt = 0;

    while(1)
    {
        sleep(2);
        printf("------------------------------------------\n");
        printf("get data from ring buffer.\n");

        {
            char i;

            if (isempty(ring_buf)) {
                printf("buffer is empty !\n");
                sleep(1);
                continue;
            }

            if (cnt !=0 && !(cnt % 16))
                printf("\n");

            get(ring_buf, &i, sizeof(i));

            printf("data is: %d \n", i);

            cnt++;
        }


        printf("ring buffer length: %u\n", len(ring_buf));
        printf("------------------------------------------\n");
    }
}

void * producer_proc(void *arg)
{
    RingBuffer *ring_buf = (RingBuffer *)arg;
    char i;

    i = 0;
    while(1)
    {
        printf("******************************************\n");
        printf("put datas to ring buffer.\n");


        if (isfull(ring_buf)) {
            printf("buffer is full !\n");
            sleep(1);
            continue;
        }
        put(ring_buf, &i, sizeof(i));
        i++;

        printf("ring buffer length: %u\n", len(ring_buf));
        printf("******************************************\n");
        sleep(1);
    }
}


pthread_t consumer_thread(void *arg)
{
    int err;
    pthread_t tid;
    err = pthread_create(&tid, NULL, consumer_proc, arg);
    if (err != 0)
    {
        fprintf(stderr, "Failed to create consumer thread.errno:%u, reason:%s\n",
                errno, strerror(errno));
        return -1;
    }
    return tid;
}
pthread_t producer_thread(void *arg)
{
    int err;
    pthread_t tid;
    err = pthread_create(&tid, NULL, producer_proc, arg);
    if (err != 0)
    {
        fprintf(stderr, "Failed to create consumer thread.errno:%u, reason:%s\n",
                errno, strerror(errno));
        return -1;
    }
    return tid;
}



int main(void)
{
    RingBuffer* ring_buf;
    pthread_t produce_pid, consume_pid;

    ring_buf = create(FIFO_SIZE);
    if (!ring_buf) {
        perror("ringbuffer_create()");
        exit(1);
    }

    printf("multi thread test.......\n");

    produce_pid  = producer_thread((void*)ring_buf);
    consume_pid  = consumer_thread((void*)ring_buf);

    pthread_join(produce_pid, NULL);
    pthread_join(consume_pid, NULL);


    destroy(ring_buf);

    return 0;
}
