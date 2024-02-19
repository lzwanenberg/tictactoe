#pragma once

#include <stdio.h>
#include "unity.h"

#include "BoardViewMapper.h"
#include "../../../models/Game/Game.h"

#define EMPTY BOARD_VIEW__CELL_EMPTY
#define P1 BOARD_VIEW__CELL_P1
#define P2 BOARD_VIEW__CELL_P2

void setUp(void)
{
}

void tearDown(void)
{
}

void map_game_to_board_view__empty_game__returns_empty(void)
{
  Game game;
  BoardView board_view;

  game__initialize(&game);

  map_game_to_board_view(&game, &board_view);

  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[0][0]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[0][1]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[0][2]);

  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[1][0]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[1][1]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[1][2]);

  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[2][0]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[2][1]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[2][2]);
}

void map_game_to_board_view__non_empty_game__returns_even_moves_p1_odd_moves_p2(void)
{
  Game game;
  BoardView board_view;

  game__load(&game, (char[][2]){{1, 1}, {1, 2}, {2, 1}, {0, 1}, {2, 0}}, 5);

  map_game_to_board_view(&game, &board_view);

  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[0][0]);
  TEST_ASSERT_EQUAL(P2, board_view.cells[0][1]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[0][2]);

  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[1][0]);
  TEST_ASSERT_EQUAL(P1, board_view.cells[1][1]);
  TEST_ASSERT_EQUAL(P2, board_view.cells[1][2]);

  TEST_ASSERT_EQUAL(P1, board_view.cells[2][0]);
  TEST_ASSERT_EQUAL(P1, board_view.cells[2][1]);
  TEST_ASSERT_EQUAL(EMPTY, board_view.cells[2][2]);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(map_game_to_board_view__empty_game__returns_empty);
  RUN_TEST(map_game_to_board_view__non_empty_game__returns_even_moves_p1_odd_moves_p2);
  UNITY_END();

  return 0;
}
