#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"
#include "../GameService/GameService.h"
#include "../../types/TicTacToe.h"
#include "MoveValidator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void validate_move_todo(void)
{
  Game game;
  initialize_game(&game);
  Move move = (Move){.col = 1, .row = 1};

  MoveValidator_Result result = validate_move(&game, &move);

  TEST_ASSERT_EQUAL(MOVE_VALIDATOR__RESULT__VALID, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(validate_move_todo);
  UNITY_END();

  return 0;
}
