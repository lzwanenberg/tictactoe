#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "MoveUtil.h"
#include "../../types/Move.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void moves_are_equal__same_col_and_row__returns_true(void)
{
  Move a = (Move){.col = 1, .row = 1};
  Move b = (Move){.col = 1, .row = 1};

  bool result = moves_are_equal(&a, &b);

  TEST_ASSERT_TRUE(result);
}

void moves_are_equal__different_rows__returns_false(void)
{
  Move a = (Move){.col = 1, .row = 1};
  Move b = (Move){.col = 1, .row = 2};

  bool result = moves_are_equal(&a, &b);

  TEST_ASSERT_FALSE(result);
}

void moves_are_equal__different_cols__returns_false(void)
{
  Move a = (Move){.col = 1, .row = 1};
  Move b = (Move){.col = 2, .row = 1};

  bool result = moves_are_equal(&a, &b);

  TEST_ASSERT_FALSE(result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(moves_are_equal__same_col_and_row__returns_true);
  RUN_TEST(moves_are_equal__different_rows__returns_false);
  RUN_TEST(moves_are_equal__different_cols__returns_false);
  UNITY_END();

  return 0;
}
