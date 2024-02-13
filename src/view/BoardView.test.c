#pragma once

#include <stdio.h>
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
  TEST_ASSERT_EQUAL_INT(1, 2); // Example assertion
}

void test_example2(void)
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
  RUN_TEST(test_example2);
  UNITY_END();
}

int main()
{
  test_suite();

  return 0;
}
