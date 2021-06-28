cmake_minimum_required(VERSION 3.8)
project(cps1011)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(app1 ${SOURCE_FILES})

set(SOURCE_FILES2 main2.c)
add_executable(app2 ${SOURCE_FILES2})

set(SOURCE_FILES3 main3.c)
add_executable(app3 ${SOURCE_FILES3})

set(SOURCE_FILES4 main4.c)
add_executable(app4 ${SOURCE_FILES4})

set(SOURCE_FILES5 main5.c)
add_executable(app5 ${SOURCE_FILES5})