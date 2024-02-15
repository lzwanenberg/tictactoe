#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "../../types/TicTacToe.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void validate_move__cell_occupied__returns_cell_occupied_code(void)
{
  TEST_ASSERT_EQUAL(1, 1);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(validate_move__cell_occupied__returns_cell_occupied_code);
  UNITY_END();

  return 0;
}
