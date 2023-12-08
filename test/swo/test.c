#include "unity.h"
#include "main.c"


void setUp(void) {
    // Set up any necessary things before each test
}

void tearDown(void) {
    // Clean up after each test
}

void test_function_should_doSomething(void) {
    // Example test
    TEST_ASSERT_EQUAL(1, 1);
    sum();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doSomething);
    return UNITY_END();
}
