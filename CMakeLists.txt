cmake_minimum_required(VERSION 3.19)
project(Dynamic_Lists C)

set(CMAKE_C_STANDARD 99)

set(SOURCES Sources/consoledata.c Sources/filedata.c Sources/list.c)
set(HEADERS Headers/inform.h)

add_executable(Dynamic_Lists main.c ${SOURCES} ${HEADERS})