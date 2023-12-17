cmake_minimum_required(VERSION 3.10)


add_library(stubs INTERFACE)

target_include_directories(stubs 
    INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
) 