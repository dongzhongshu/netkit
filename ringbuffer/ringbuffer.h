//
// Created by Administrator on 2020/1/11.
//

#ifndef NETKIT_RINGBUFFER_H
#define NETKIT_RINGBUFFER_H
/*
 * 如果是一个线程读，一个线程写时，可以用无锁队列
 */
#include <stdbool.h>
#include <stdio.h>

typedef struct _ringbuffer{
    void* data;
    unsigned int size;
    unsigned int readpos;//注意此处用的是unsigned
    unsigned int writepos;//同上
}RingBuffer;
RingBuffer* create(unsigned int size);
void destroy(RingBuffer* ringbuffer);
void reset(RingBuffer* ringbuffer);
unsigned int put(RingBuffer* ringbuffer, const char* buf, unsigned int len);
unsigned int get(RingBuffer* ringbuffer, char* buf, unsigned int getlen);
bool isempty(RingBuffer* ringbuffer);
bool isfull(RingBuffer* ringbuffer);
unsigned int len(RingBuffer* ringbuffer);
unsigned int space_left(RingBuffer* ringbuffer);
#endif //NETKIT_RINGBUFFER_H
