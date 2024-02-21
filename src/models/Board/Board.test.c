#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "Board.h"
#include "../../models/Move/Move.h"
#include "../../config.h"

#define EMPTY BOARD__CELL__EMPTY
#define P1 BOARD__CELL__P1
#define P2 BOARD__CELL__P2

void setUp(void)
{
}

void tearDown(void)
{
}

void count_non_empty_cells__empty_game__returns_0(void)
{
  Board board;
  board__initialize(&board);

  char actual = board__count_non_empty_cells(&board);

  TEST_ASSERT_EQUAL(0, actual);
}

void count_non_empty_cells__ongoing_game__returns_amount_of_markers(void)
{
  Board board;
  char moves[][2] = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}};

  board__initialize(&board);
  board__load(&board, moves, 5);

  char actual = board__count_non_empty_cells(&board);

  TEST_ASSERT_EQUAL(5, actual);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(count_non_empty_cells__empty_game__returns_0);
  RUN_TEST(count_non_empty_cells__ongoing_game__returns_amount_of_markers);
  UNITY_END();

  return 0;
}
