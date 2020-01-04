//
// Created by Administrator on 2020/1/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "thread_pool.h"

static void* write_file(void* argv)
{
    char path[128] = {0};
    int file_index = *((int*)argv);

    printf("will write file:%d\n", file_index);
    //please check there is test directory under your current directory
    snprintf(path, 128, "test/%d.txt", file_index);

    FILE* file_ptr = fopen(path, "w+");
    if (file_ptr != NULL)
    {
        char *str="hello,I am a test program!\r\n";
        for(int i = 0; i < 100; i++)
        {
            fwrite(str, sizeof(char), strlen(str), file_ptr);
        }

        fclose(file_ptr);
    }
    else
    {
        printf("write file failed.\n");
    }

    return NULL;
}

int main()
{
    int task_count = 100;

    time_t start = clock();

    threadpool_config(threadpool_eventfd_type);

    threadpool_t* pool = threadpool_create(8, 65535, 0);

    int* file_index = (int*)malloc(sizeof(int) * task_count);
    for (int i = 0; i < task_count; i ++)
    {
        file_index[i] = i;
    }

    for (int i = 0 ; i < task_count; i ++)
    {
//        printf("will push file:%d\n", file_index[i]);
        if(0 != threadpool_add(pool, write_file, (void*)&file_index[i]))
        {
            printf("add task to thread pool failed.\n");
        }
    }

#if 1
    if (0 != threadpool_destroy(pool, threadpool_graceful))
    {
        printf("destroy thread pool failed.\n");
    }
#endif

    time_t end = clock();
    double seconds  =(double)(end - start)/CLOCKS_PER_SEC;
    printf("cost: %lf\n", seconds);

//    for(;;);
    return 0;
}