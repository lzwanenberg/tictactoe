#pragma once

#include <stdio.h>
#include "AnotherHelper.c"
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
void test_increment_1(void)
{
  TEST_ASSERT_EQUAL_INT(another_increment(2), 3);
}

void test_increment_2(void)
{
  TEST_ASSERT_EQUAL_INT(another_increment(6), 7);
}

void test_increment_3(void)
{
  TEST_ASSERT_EQUAL_INT(another_increment(1), 2);
}

// Define the test suite
void test_suite(void)
{
  // Register setup and teardown functions
  UNITY_BEGIN();
  // RUN_TEST(test_increment_1);
  // RUN_TEST(test_increment_2);
  // RUN_TEST(test_increment_3);
  UNITY_END();
}

int main()
{
  test_suite();

  return 0;
}
