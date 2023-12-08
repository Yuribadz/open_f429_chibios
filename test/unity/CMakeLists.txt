cmake_minimum_required(VERSION 3.10)

set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "Enable Unity Fixture Extension")
set(UNITY_EXTENSION_MEMORY  ON CACHE BOOL "Enable Unity Memory Extension")


add_library(Unity STATIC
    ${PROJECT_SOURCE_DIR}/test/Unity/src/unity.c
    ${PROJECT_SOURCE_DIR}/test/Unity/extras/fixture/src/unity_fixture.c
    ${PROJECT_SOURCE_DIR}/test/Unity/extras/memory/src/unity_memory.c
)
target_include_directories(Unity PUBLIC
    ${PROJECT_SOURCE_DIR}/test/Unity/src
    ${PROJECT_SOURCE_DIR}/test/Unity/extras/fixture/src
    ${PROJECT_SOURCE_DIR}/test/Unity/extras/memory/src
    ${PROJECT_SOURCE_DIR}/test/unity
)