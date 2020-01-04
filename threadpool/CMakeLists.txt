cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-std=c99")
add_executable(netkit queue.c async_queue_cond.c threadpool.c main.c async_queue_event.c)
TARGET_LINK_LIBRARIES(netkit pthread)