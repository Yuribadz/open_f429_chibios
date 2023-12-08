cmake_minimum_required(VERSION 3.10)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
set(CMAKE_C_STANDARD 99)

include(CTest)
include(CodeCoverage)


APPEND_COVERAGE_COMPILER_FLAGS()
# Add executable for the tests
add_subdirectory(cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

add_executable(run_tests ${PROJECT_SOURCE_DIR}/swo/test.c)

target_link_libraries(run_tests
    Unity
)
target_sources(run_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/source/swo_debug/swo_print.c
)
target_include_directories(run_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/source/swo_debug
)

setup_target_for_coverage_gcovr_html(
    NAME coverage
    EXECUTABLE run_tests
    BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src"
    EXCLUDE "unity/*")
    # DEPENDENCIES run_tests)

add_test(test_run_tests run_tests)