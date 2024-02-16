#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "GameStatusAnalyzer.h"
#include "../../../stubs/Game/Game.h"
#include "../GameService/GameService.h"

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
  load_game(&game, moves, size);
  return game;
}

void analyze_game_status__ongoing_turn_p1(void)
{
  Game game = game_stub__ongoing_turn_p1();

  GameStatusService_Result result = analyze_game_status(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1, result);
}

void analyze_game_status__ongoing_turn_p2(void)
{
  Game game = game_stub__ongoing_turn_p2();

  GameStatusService_Result result = analyze_game_status(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2, result);
}

void analyze_game_status__p1_row1_3_in_a_row__returns_p1_won(void)
{
  static char MOVES[][2] = {A1, A2, B1, B2, C1};
  Game game = CREATE_GAME(MOVES);

  GameStatusService_Result result = analyze_game_status(&game);

  TEST_ASSERT_EQUAL(GAME_STATUS_SERVICE__RESULT__P1_WON, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(analyze_game_status__ongoing_turn_p1);
  RUN_TEST(analyze_game_status__ongoing_turn_p2);
  RUN_TEST(analyze_game_status__p1_row1_3_in_a_row__returns_p1_won);
  UNITY_END();

  return 0;
}
