#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"
#include "../../models/Board/Board.h"
#include "../../models/Move/Move.h"
#include "MoveValidator.h"
#include "../../../stubs/Board/Board.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void validate__valid_move__returns_valid(void)
{
  Board board;
  board__load(&board, (char[][2]){{1, 1}, {0, 0}}, 2);

  Move move = (Move){.col = 2, .row = 2};

  MoveValidator_Result result = move_validator__validate(&board, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__VALID, result);
}

void validate__cell_already_occupied__returns_invalid(void)
{
  Board board;
  board__load(&board, (char[][2]){{1, 1}, {1, 2}, {2, 1}}, 3);

  Move move = (Move){.col = 1, .row = 2};

  MoveValidator_Result result = move_validator__validate(&board, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED, result);
}

void validate__move_out_of_bounds__returns_invalid(void)
{
  Board board = board_stub__ongoing();

  Move out_of_bound_moves[4] = {
      (Move){.col = -1, .row = 0},
      (Move){.col = 3, .row = 0},
      (Move){.col = 0, .row = -1},
      (Move){.col = 0, .row = 3}};

  for (int i = 0; i < 4; i++)
  {
    Move move = out_of_bound_moves[i];

    MoveValidator_Result result = move_validator__validate(&board, &move);

    TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS, result);
  }
}

void validate__gamed_ended_draw__returns_invalid(void)
{
  Board board = board_stub__draw();
  Move move = (Move){.col = 1, .row = 1};

  MoveValidator_Result result = move_validator__validate(&board, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_FINISHED, result);
}

void validate__game_ended_win_p1__returns_invaild(void)
{
  Board board = board_stub__p1_won();
  Move move = (Move){.col = 1, .row = 1};

  MoveValidator_Result result = move_validator__validate(&board, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_FINISHED, result);
}

void validate__game_ended_win_p2__returns_invaild(void)
{
  Board board = board_stub__p2_won();
  Move move = (Move){.col = 1, .row = 1};

  MoveValidator_Result result = move_validator__validate(&board, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_FINISHED, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(validate__valid_move__returns_valid);
  RUN_TEST(validate__move_out_of_bounds__returns_invalid);
  RUN_TEST(validate__cell_already_occupied__returns_invalid);
  RUN_TEST(validate__gamed_ended_draw__returns_invalid);
  RUN_TEST(validate__game_ended_win_p1__returns_invaild);
  RUN_TEST(validate__game_ended_win_p2__returns_invaild);
  UNITY_END();

  return 0;
}
