//
// Created by Administrator on 2020/1/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "ringbuffer.h"
#include <unistd.h>

#define min(x,y) ({ 			\
		typeof(x) _x = (x);	\
		typeof(y) _y = (y);	\
		(void) (&_x == &_y);	\
		_x < _y ? _x : _y; })

static bool is_power_of_2(unsigned long n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}

static unsigned long roundup_power_of_two(unsigned long n)
{
    if((n & (n-1)) == 0)
        return n;

    unsigned long maxulong = (unsigned long)((unsigned long)~0);
    unsigned long andv = ~(maxulong&(maxulong>>1));

    while((andv & n) == 0)
        andv = andv>>1;

    return andv<<1;
}
RingBuffer* create(unsigned int size)
{
    RingBuffer* ringbuffer;
    unsigned int buffersize = size;
    if(!is_power_of_2(size)){
        buffersize = roundup_power_of_two(size);
    }
    ringbuffer = calloc(1, sizeof(RingBuffer));
    if(ringbuffer == NULL){
        return NULL;
    }
    ringbuffer->data = malloc(buffersize* sizeof(char));
    if(ringbuffer->data == NULL){
        free(ringbuffer);
        return NULL;
    }
    ringbuffer->size = buffersize;
    return ringbuffer;
}

void destroy(RingBuffer* ringbuffer)
{
    if(ringbuffer == NULL){
        return;
    }
    if(ringbuffer->data != NULL){
        free(ringbuffer->data);
        ringbuffer->data = NULL;
    }
    free(ringbuffer);
}
void reset(RingBuffer* ringbuffer)
{
    if(ringbuffer){
        ringbuffer->readpos = ringbuffer->writepos = 0;
    }
}

unsigned int put(RingBuffer* ringbuffer, const char* buf, unsigned int len)
{
    //注意：利用上unsigned int回绕的特性
    if(ringbuffer == NULL || buf == NULL || len == 0){
        return 0;
    }
    unsigned putlen = min(len, ringbuffer->size - ringbuffer->writepos + ringbuffer->readpos);
    unsigned l = min(putlen, ringbuffer->size - (ringbuffer->writepos & (ringbuffer->size - 1)));
    memcpy(ringbuffer->data + (ringbuffer->writepos&(ringbuffer->size - 1)), buf, l);
    memcpy(ringbuffer->data, buf+l, putlen - l);
    ringbuffer->writepos += putlen;//注意此处，writepos会一直增长。
    return putlen;
}

unsigned int get(RingBuffer* ringbuffer, char* buf, unsigned int len)
{
    //注意：利用上unsigned int回绕的特性
    if(ringbuffer == NULL || buf == NULL || len == 0){
        return 0;
    }
    unsigned getlen = min(len, ringbuffer->writepos - ringbuffer->readpos);
    unsigned l = min(len, ringbuffer->size - (ringbuffer->readpos & (ringbuffer->size - 1)));
    memcpy(buf, ringbuffer->data + (ringbuffer->readpos & (ringbuffer->size - 1)), l);
    memcpy(buf+l, ringbuffer->data, getlen - l);
    ringbuffer->readpos += getlen;//注意此处，writepos会一直增长。
    return getlen;
}

bool isempty(RingBuffer* ringbuffer)
{
    if(ringbuffer == NULL){
        return false;
    }
    return ringbuffer->readpos == ringbuffer->writepos;
}
bool isfull(RingBuffer* ringbuffer)
{
    if(ringbuffer == NULL){
        return false;
    }
    return ringbuffer->size == (ringbuffer->writepos - ringbuffer->readpos);
}

unsigned int len(RingBuffer* ringbuffer)
{
    if(ringbuffer == NULL){
        return false;
    }
    return (ringbuffer->writepos - ringbuffer->readpos);
}

unsigned int space_left(RingBuffer* ringbuffer)
{
    if(ringbuffer == NULL){
        return false;
    }
    return ringbuffer->size -(ringbuffer->writepos - ringbuffer->readpos);
}