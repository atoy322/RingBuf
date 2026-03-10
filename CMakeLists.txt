cmake_minimum_required(VERSION 3.5)

project(ringbuf C)

add_library(ringbuf STATIC ringbuf.c)
target_include_directories(ringbuf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_EXAMPLE)
    add_executable(test test.c)
    target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(test ringbuf)
endif()
