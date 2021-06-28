cmake_minimum_required(VERSION 3.8)
project(cps1011q2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES hashtable.h main.c)
add_library(hashtable1 SHARED ${SOURCE_FILES})

set(SOURCE_FILES2 hashtable.h main2.c)
add_library(hashtable2 SHARED ${SOURCE_FILES2})

set(SOURCE_FILES3 hashtable.h main3.c)
add_library(hashtable3 SHARED ${SOURCE_FILES3})

set(SOURCE_FILES4 test.c hashtable.h)
add_executable(test1 ${SOURCE_FILES4})
target_link_libraries(test1 hashtable1)

set(SOURCE_FILES5 test.c hashtable.h)
add_executable(test2 ${SOURCE_FILES5})
target_link_libraries(test2 hashtable2)

set(SOURCE_FILES6 test.c hashtable.h)
add_executable(test3 ${SOURCE_FILES6})
target_link_libraries(test3 hashtable3)