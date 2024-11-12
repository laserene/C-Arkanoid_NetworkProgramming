cmake_minimum_required(VERSION 3.29)
project(C_Arkanoid_NetworkProgramming C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Arkanoid_NetworkProgramming
    client.c
    server.c
)
