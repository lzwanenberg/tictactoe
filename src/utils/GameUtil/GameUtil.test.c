#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "GameUtil.h"
#include "../../../stubs/Game/Game.h"
#include "../../types/Move.h"
#include "../../config.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void count_number_of_moves__empty_game__returns_0(void)
{
  Game game = game_stub__empty();

  char result = count_number_of_moves(&game);

  TEST_ASSERT_EQUAL(0, result);
}

void count_number_of_moves__ongoing_game__returns_number_of_moves(void)
{
  Game game;
  load_game(&game, (char[][2]){{1, 1}, {1, 2}, {2, 1}}, 3);

  char result = count_number_of_moves(&game);

  TEST_ASSERT_EQUAL(3, result);
}

void count_number_of_moves__drawn_game__returns_max_game_length(void)
{
  Game game = game_stub__draw();

  char result = count_number_of_moves(&game);

  TEST_ASSERT_EQUAL(MAX_MOVES, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(count_number_of_moves__empty_game__returns_0);
  RUN_TEST(count_number_of_moves__ongoing_game__returns_number_of_moves);
  RUN_TEST(count_number_of_moves__drawn_game__returns_max_game_length);
  UNITY_END();

  return 0;
}
