#pragma once

#include <stdio.h>
#include "unity.h"

#include "../Game/Game.h";
#include "GameState.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void todo_test(void)
{
  Game game;
  initialize_game(&game);

  GameState state = calculate_game_state(&game);

  TEST_ASSERT_EQUAL(GAME_STATE__WAIT_FOR_MOVE_P1, state);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(todo_test);
  UNITY_END();

  return 0;
}
