cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-std=c99")
add_executable(ringbuffer ringbuffer.h ringbuffer.c main.c)
TARGET_LINK_LIBRARIES(ringbuffer pthread)