#pragma once

#include <stdio.h>
#include "unity.h"
#include "Greeter.c"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_greeter(void)
{
  const char *message = greet("World");

  char *expected = "Hello, World!";

  TEST_ASSERT_EQUAL_STRING(expected, message);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_greeter);
  UNITY_END();

  return 0;
}
