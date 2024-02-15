#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

#include "Game.h"
#include "../GameState/GameState.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void attempt_make_move__valid_move_on_empty_board__returns_move_validity__valid(void)
{
  Game game;
  initialize_game(&game);

  Game_MoveResult result = attempt_make_move(&game, &(Game_Move){1, 1});

  TEST_ASSERT_EQUAL(GAME__MOVE_VALIDITY__VALID, result.move_validity);
}

// void attempt_make_move__valid_move_on_empty_board__returns_state__wait_for_move_p2(void)
// {
//   Game game;
//   initialize_game(&game);

//   Game_MoveResult result = attempt_make_move(&game, &(Game_Move){1, 1});

//   TEST_ASSERT_EQUAL(GAME_STATE__WAIT_FOR_MOVE_P2, result.state);
// }

void attempt_make_move__valid_move_by_p2__returns_move_validity__valid(void)
{
  Game game;
  initialize_game(&game);

  attempt_make_move(&game, &(Game_Move){1, 1});

  Game_MoveResult result = attempt_make_move(&game, &(Game_Move){1, 2});

  TEST_ASSERT_EQUAL(GAME__MOVE_VALIDITY__VALID, result.move_validity);
}

// void attempt_make_move__valid_move_by_p2__returns_state__wait_for_move_p1(void)
// {
//   Game game;
//   initialize_game(&game);

//   attempt_make_move(&game, &(Game_Move){1, 1});

//   Game_MoveResult result = attempt_make_move(&game, &(Game_Move){1, 2});

//   TEST_ASSERT_EQUAL(GAME_STATE__WAIT_FOR_MOVE_P1, result.state);
// }

void attempt_make_move__winning_move_by_p1__returns_move_validity__valid(void)
{

  Game game;
  initialize_game(&game);

  attempt_make_move(&game, &(Game_Move){0, 0});
  attempt_make_move(&game, &(Game_Move){1, 0});
  attempt_make_move(&game, &(Game_Move){0, 1});
  attempt_make_move(&game, &(Game_Move){1, 1});

  Game_MoveResult result = attempt_make_move(&game, &(Game_Move){0, 2});

  TEST_ASSERT_EQUAL(GAME__MOVE_VALIDITY__VALID, result.move_validity);
}

// void attempt_make_move__winning_move_by_p1__returns_state__wait_for_move_p1(void)
// {

//   Game game;
//   initialize_game(&game);

//   attempt_make_move(&game, &(Game_Move){0, 0});
//   attempt_make_move(&game, &(Game_Move){1, 0});
//   attempt_make_move(&game, &(Game_Move){0, 1});
//   attempt_make_move(&game, &(Game_Move){1, 1});

//   Game_MoveResult result = attempt_make_move(&game, &(Game_Move){0, 2});

//   TEST_ASSERT_EQUAL(GAME_STATE__P1_WON, result.state);
// }

int main()
{
  UNITY_BEGIN();
  RUN_TEST(attempt_make_move__valid_move_on_empty_board__returns_move_validity__valid);
  // RUN_TEST(attempt_make_move__valid_move_on_empty_board__returns_state__wait_for_move_p2);
  RUN_TEST(attempt_make_move__valid_move_by_p2__returns_move_validity__valid);
  // RUN_TEST(attempt_make_move__valid_move_by_p2__returns_state__wait_for_move_p1);
  RUN_TEST(attempt_make_move__winning_move_by_p1__returns_move_validity__valid);
  // RUN_TEST(attempt_make_move__winning_move_by_p1__returns_state__wait_for_move_p1);
  UNITY_END();

  return 0;
}
