#pragma once

#include <stdio.h>
#include "unity.h"
#include "Move.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void is_empty_move__empty_move__returns_true(void)
{
  Move empty_move = create_empty_move();

  bool result = is_empty_move(&empty_move);

  TEST_ASSERT_TRUE(result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(is_empty_move__empty_move__returns_true);
  UNITY_END();

  return 0;
}