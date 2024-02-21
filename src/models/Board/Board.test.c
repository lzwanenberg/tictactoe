#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "Board.h"
#include "../Game/Game.h"
#include "../../../stubs/Game/Game.h"
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

void map_game_to_board__empty_game__returns_empty(void)
{
  Game game;
  Board board;

  game__initialize(&game);
  board__initialize(&board);
  board__update(&board, &game);

  TEST_ASSERT_EQUAL(EMPTY, board.cells[0][0]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[0][1]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[0][2]);

  TEST_ASSERT_EQUAL(EMPTY, board.cells[1][0]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[1][1]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[1][2]);

  TEST_ASSERT_EQUAL(EMPTY, board.cells[2][0]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[2][1]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[2][2]);
}

void map_game_to_board__non_empty_game__returns_even_moves_p1_odd_moves_p2(void)
{
  Game game;
  Board board;

  game__initialize(&game);
  game__load(&game, (char[][2]){{1, 1}, {1, 2}, {2, 1}, {0, 1}, {2, 0}}, 5);

  board__initialize(&board);
  board__update(&board, &game);

  TEST_ASSERT_EQUAL(EMPTY, board.cells[0][0]);
  TEST_ASSERT_EQUAL(P2, board.cells[0][1]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[0][2]);

  TEST_ASSERT_EQUAL(EMPTY, board.cells[1][0]);
  TEST_ASSERT_EQUAL(P1, board.cells[1][1]);
  TEST_ASSERT_EQUAL(P2, board.cells[1][2]);

  TEST_ASSERT_EQUAL(P1, board.cells[2][0]);
  TEST_ASSERT_EQUAL(P1, board.cells[2][1]);
  TEST_ASSERT_EQUAL(EMPTY, board.cells[2][2]);
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
  RUN_TEST(map_game_to_board__empty_game__returns_empty);
  RUN_TEST(map_game_to_board__non_empty_game__returns_even_moves_p1_odd_moves_p2);
  RUN_TEST(count_non_empty_cells__empty_game__returns_0);
  RUN_TEST(count_non_empty_cells__ongoing_game__returns_amount_of_markers);
  UNITY_END();

  return 0;
}
