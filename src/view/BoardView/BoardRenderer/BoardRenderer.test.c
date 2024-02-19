#pragma once

#include <stdio.h>
#include "unity.h"

#include "../BoardView.h"
#include "BoardRenderer.h"

#define _ BOARD_VIEW__CELL_EMPTY
#define X BOARD_VIEW__CELL_P1
#define O BOARD_VIEW__CELL_P2

void setUp(void)
{
}

void tearDown(void)
{
}

void empty_board__renders_correctly(void)
{
  char buffer[OUTPUT_BUFFER_SIZE];
  buffer[0] = '\n';

  BoardView board_view = {
      .cells = {{_, _, _},
                {_, _, _},
                {_, _, _}}};

  render_board_view(&board_view, buffer);

  char *expected =
      "   A   B   C\n"
      "1  _ | _ | _\n"
      "2  _ | _ | _\n"
      "3  _ | _ | _\n";

  TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

void non_empty_board__renders_correctly(void)
{
  char buffer[OUTPUT_BUFFER_SIZE];
  buffer[0] = '\n';

  BoardView board_view = {
      .cells = {{_, X, O},
                {O, O, X},
                {X, _, _}}};

  render_board_view(&board_view, buffer);

  char *expected =
      "   A   B   C\n"
      "1  _ | X | O\n"
      "2  O | O | X\n"
      "3  X | _ | _\n";

  TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(empty_board__renders_correctly);
  RUN_TEST(non_empty_board__renders_correctly);
  UNITY_END();

  return 0;
}
