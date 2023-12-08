cmake_minimum_required(VERSION 3.10)

add_library(Unity STATIC
    lib/Unity/src/unity.c
)

target_include_directories(Unity PUBLIC
    lib/Unity/src
)