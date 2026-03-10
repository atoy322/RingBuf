cmake_minimum_required(VERSION 3.5)

project(ringbuf C)

add_library(ringbuf STATIC ringbuf.c)
target_include_directories(ringbuf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

