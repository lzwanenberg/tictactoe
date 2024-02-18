#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "Move.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void is_equal__same_col_and_row__returns_true(void)
{
  Move a, b;
  move__create(&a, 1, 2);
  move__create(&b, 1, 2);

  bool result = move__is_equal(&a, &b);

  TEST_ASSERT_TRUE(result);
}

void is_equal__different_rows__returns_false(void)
{
  Move a, b;
  move__create(&a, 1, 1);
  move__create(&b, 1, 2);

  bool result = move__is_equal(&a, &b);

  TEST_ASSERT_FALSE(result);
}

void is_equal__different_cols__returns_false(void)
{
  Move a, b;
  move__create(&a, 1, 1);
  move__create(&b, 2, 1);

  bool result = move__is_equal(&a, &b);

  TEST_ASSERT_FALSE(result);
}

int main()
{
  // TODO missing test cases
  UNITY_BEGIN();
  RUN_TEST(is_equal__same_col_and_row__returns_true);
  RUN_TEST(is_equal__different_rows__returns_false);
  RUN_TEST(is_equal__different_cols__returns_false);
  UNITY_END();

  return 0;
}