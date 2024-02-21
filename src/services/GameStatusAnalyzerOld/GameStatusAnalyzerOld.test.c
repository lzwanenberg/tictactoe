#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "GameStatusAnalyzerOld.h"
#include "../../../stubs/Game/Game.h"

#define CREATE_GAME(arr) create_non_empty(arr, sizeof(arr) / sizeof(arr[0]))

#define CELL(col, row) \
  {                    \
    col, row           \
  }

#define A1 CELL(0, 0)
#define A2 CELL(0, 1)
#define A3 CELL(0, 2)
#define B1 CELL(1, 0)
#define B2 CELL(1, 1)
#define B3 CELL(1, 2)
#define C1 CELL(2, 0)
#define C2 CELL(2, 1)
#define C3 CELL(2, 2)

void setUp(void)
{
}

void tearDown(void) {}

static Game create_non_empty(char moves[][2], int size)
{
  Game game;
  game__load(&game, moves, size);
  return game;
}

void analyze__ongoing_turn_p1(void)
{
  Game game = game_stub__ongoing_turn_p1();

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1, result);
}

void analyze__ongoing_turn_p2(void)
{
  Game game = game_stub__ongoing_turn_p2();

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2, result);
}

void analyze__p1_row1_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A1, A2, B1, B2, C1};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_row2_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A2, A1, B2, A3, C2};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_row3_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A3, A1, B3, A2, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_col1_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A1, B1, A2, B2, A3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_col2_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {B1, C1, B2, C2, B3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_col3_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {C1, A1, C2, A2, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_diagonal1_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A1, A1, B2, A2, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p1_diagonal2_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {C1, A1, B2, A2, A3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

void analyze__p2_row1_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {A3, A1, A2, B1, B2, C1};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_row2_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {A1, A2, A3, B2, B3, C2};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_row3_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {A2, A3, A1, B3, B1, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_col1_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {C2, A1, B1, A2, B2, A3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_col2_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {A2, B1, C1, B2, C2, B3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_col3_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {B2, C1, A1, C2, B2, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_diagonal1_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {B1, A1, A1, B2, A2, C3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__p2_diagonal2_3_in_a_row__returns_p2_won(void)
{
  static char MOVES[][2] = {B1, C1, A1, B2, A2, A3};
  Game game = CREATE_GAME(MOVES);

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P2_WON, result);
}

void analyze__9_moves_without_winner__returns_draw(void)
{
  Game game = game_stub__draw();

  GameStatusAnalyzerOld_Result result = game_status_analyzer_old__analyze(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__DRAW, result);
}

int main()
{
  UNITY_BEGIN();

  // ONGOING
  RUN_TEST(analyze__ongoing_turn_p1);
  RUN_TEST(analyze__ongoing_turn_p2);

  // DRAW
  RUN_TEST(analyze__9_moves_without_winner__returns_draw);

  // P1 WIN
  // P1 - rows
  RUN_TEST(analyze__p1_row1_3_in_a_row__returns_p1_won);
  RUN_TEST(analyze__p1_row2_3_in_a_row__returns_p1_won);
  RUN_TEST(analyze__p1_row3_3_in_a_row__returns_p1_won);

  // P1 - columns
  RUN_TEST(analyze__p1_col1_3_in_a_row__returns_p1_won);
  RUN_TEST(analyze__p1_col2_3_in_a_row__returns_p1_won);
  RUN_TEST(analyze__p1_col3_3_in_a_row__returns_p1_won);

  // P1 - diagonals
  RUN_TEST(analyze__p1_diagonal1_3_in_a_row__returns_p1_won);
  RUN_TEST(analyze__p1_diagonal2_3_in_a_row__returns_p1_won);

  // P2 WIN
  // P2 - rows
  RUN_TEST(analyze__p2_row1_3_in_a_row__returns_p2_won);
  RUN_TEST(analyze__p2_row2_3_in_a_row__returns_p2_won);
  RUN_TEST(analyze__p2_row3_3_in_a_row__returns_p2_won);

  // P2 - columns
  RUN_TEST(analyze__p2_col1_3_in_a_row__returns_p2_won);
  RUN_TEST(analyze__p2_col2_3_in_a_row__returns_p2_won);
  RUN_TEST(analyze__p2_col3_3_in_a_row__returns_p2_won);

  // P2 - diagonals
  RUN_TEST(analyze__p2_diagonal1_3_in_a_row__returns_p2_won);
  RUN_TEST(analyze__p2_diagonal2_3_in_a_row__returns_p2_won);

  UNITY_END();

  return 0;
}
