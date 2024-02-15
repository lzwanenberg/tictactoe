#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "GameStatusAnalyzer.h"
#include "../../../stubs/Game/Game.h"

void setUp(void)
{
}

void tearDown(void)
{
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

int main()
{
  UNITY_BEGIN();
  RUN_TEST(analyze_game_status__ongoing_turn_p1);
  RUN_TEST(analyze_game_status__ongoing_turn_p2);
  UNITY_END();

  return 0;
}
