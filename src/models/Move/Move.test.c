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

void create__sets_values(void)
{
  Move a;
  move__create(&a, 1, 2);

  TEST_ASSERT_EQUAL(a.col, 1);
  TEST_ASSERT_EQUAL(a.row, 2);
}

void set__sets_values(void)
{
  Move a;
  move__initialize(&a);
  move__set(&a, 1, 2);

  TEST_ASSERT_EQUAL(a.col, 1);
  TEST_ASSERT_EQUAL(a.row, 2);

  move__set(&a, 2, 0);
  TEST_ASSERT_EQUAL(a.col, 2);
  TEST_ASSERT_EQUAL(a.row, 0);
}

void empty__sets_values_to_minus_1(void)
{
  Move a;
  move__initialize(&a);

  move__set(&a, 1, 2);
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

void is_empty__initialized_move_without_values__returns_true(void)
{
  Move a;
  move__initialize(&a);

  bool result = move__is_empty(&a);

  TEST_ASSERT_TRUE(result);
}

void is_empty__move_with_values__returns_false(void)
{
  Move a;
  move__initialize(&a);
  move__set(&a, 1, 2);
  bool result = move__is_empty(&a);

  TEST_ASSERT_FALSE(result);
}

void is_empty__emptied_move__returns_true(void)
{
  Move a;
  move__initialize(&a);
  move__set(&a, 1, 2);
  move__empty(&a);

  bool result = move__is_empty(&a);

  TEST_ASSERT_TRUE(result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(create__sets_values);
  RUN_TEST(set__sets_values);
  RUN_TEST(empty__sets_values_to_minus_1);
  RUN_TEST(is_equal__same_col_and_row__returns_true);
  RUN_TEST(is_equal__different_rows__returns_false);
  RUN_TEST(is_equal__different_cols__returns_false);
  RUN_TEST(is_empty__emptied_move__returns_true);
  RUN_TEST(is_empty__initialized_move_without_values__returns_true);
  RUN_TEST(is_empty__move_with_values__returns_false);
  UNITY_END();

  return 0;
}