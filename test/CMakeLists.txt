cmake_minimum_required(VERSION 3.10)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/test/cmake")
set(CMAKE_C_STANDARD 99)

include(CTest)
include(CodeCoverage)


APPEND_COVERAGE_COMPILER_FLAGS()
# Add executable for the tests
add_subdirectory(test_config)
add_subdirectory(fff)
add_subdirectory(stub)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

add_executable(run_tests swo/test.c)


target_link_libraries(run_tests
    Unity
    fff
    stubs
)
target_sources(run_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/source/swo_debug/src/swo_print.c
)
target_include_directories(run_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/test/swo
)

setup_target_for_coverage_gcovr_html(
    NAME coverage
    EXECUTABLE run_tests
    BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/"
    EXCLUDE "test/*" "deps/*")
    # DEPENDENCIES run_tests)

add_test(test_run_tests run_tests)