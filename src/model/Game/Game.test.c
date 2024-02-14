#pragma once

#include <stdio.h>
#include "unity.h"

#include "Game.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initialize_game(void)
{
  Game game;

  initialize_game(&game);

  TEST_ASSERT_EQUAL_INT(1, 1);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_initialize_game);
  UNITY_END();

  return 0;
}
