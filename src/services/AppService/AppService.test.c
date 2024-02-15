#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_todo(void)
{
  TEST_ASSERT_EQUAL(1, 1);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_todo);
  UNITY_END();

  return 0;
}
