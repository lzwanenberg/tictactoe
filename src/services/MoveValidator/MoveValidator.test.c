#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"
#include "../GameService/GameService.h"
#include "../../types/TicTacToe.h"
#include "MoveValidator.h"
#include "../../../stubs/Game/Game.h"
#include "../../utils/MoveUtil/MoveUtil.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void validate__valid_move__returns_valid(void)
{
  Game game;
  game_service__load_game(&game, (char[][2]){{1, 1}, {0, 0}}, 2);

  Move move = create_move(2, 2);

  MoveValidator_Result result = move_validator__validate(&game, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__VALID, result);
}

void validate__cell_already_occupied__returns_invalid(void)
{
  Game game;
  game_service__load_game(&game, (char[][2]){{1, 1}, {1, 2}, {2, 1}}, 3);

  Move move = create_move(1, 2);

  MoveValidator_Result result = move_validator__validate(&game, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED, result);
}

void validate__move_out_of_bounds__returns_invalid(void)
{
  Game game = game_stub__ongoing();

  Move out_of_bound_moves[4] = {
      create_move(-1, 0),
      create_move(3, 0),
      create_move(0, -1),
      create_move(0, 3)};

  for (int i = 0; i < 4; i++)
  {
    Move move = out_of_bound_moves[i];

    MoveValidator_Result result = move_validator__validate(&game, &move);

    TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS, result);
  }
}

void validate__gamed_ended_draw__returns_invalid(void)
{
  Game game = game_stub__draw();
  Move move = create_move(1, 1);

  MoveValidator_Result result = move_validator__validate(&game, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_FINISHED, result);
}

void validate__game_ended_win_p1__returns_invaild(void)
{
  Game game = game_stub__p1_won();
  Move move = create_move(1, 1);

  MoveValidator_Result result = move_validator__validate(&game, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__INVALID_FINISHED, result);
}

void validate__game_ended_win_p2__returns_invaild(void)
{
  Game game = game_stub__p2_won();
  Move move = create_move(1, 1);

  MoveValidator_Result result = move_validator__validate(&game, &move);

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
