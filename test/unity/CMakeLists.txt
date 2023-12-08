cmake_minimum_required(VERSION 3.10)

add_library(Unity STATIC
    ${PROJECT_SOURCE_DIR}/deps/Unity/src/unity.c
)

target_include_directories(Unity PUBLIC
    ${PROJECT_SOURCE_DIR}/deps/Unity/src
)