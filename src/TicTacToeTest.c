#include <stdio.h>
#include "modulea/Helper.c"
#include "modulea/DumbExample.c"
#include "moduleb/Helper.c"
#include "unity.h"

// Setup function called before each test case
void setUp(void)
{
	// Perform any necessary setup here
}

// Teardown function called after each test case
void tearDown(void)
{
	// Perform any necessary teardown here
}

// Test function
void test_example(void)
{
	// Test code goes here
	TEST_ASSERT_EQUAL_INT(1, 1); // Example assertion
}

// Define the test suite
void test_suite(void)
{
	// Register setup and teardown functions
	UNITY_BEGIN();
	RUN_TEST(test_example);
	UNITY_END();
}

int main()
{
	test_suite();

	return 0;
}
