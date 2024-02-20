#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "Game.h"
#include "../../../stubs/Game/Game.h"
#include "../../models/Move/Move.h"
#include "../../config.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void initialize__sets_all_moves_to_empty(void)
{
  Game game;
  game__initialize(&game);

  for (int move = 0; move < MAX_MOVES; move++)
  {
    TEST_ASSERT_TRUE(move__is_empty(&game.moves[move]));
  }
}

void load__empty_game__sets_all_moves_to_empty(void)
{
  Game game;
  game__load(&game, NULL, 0);

  for (int move = 0; move < MAX_MOVES; move++)
    TEST_ASSERT_TRUE(move__is_empty(&game.moves[move]));
}

void load__ongoing_game__sets_all_correct_moves(void)
{
  Game game;
  int moves_given = 3;
  game__load(&game, (char[][2]){{0, 1}, {1, 2}, {2, 0}}, moves_given);

  TEST_ASSERT_EQUAL(0, game.moves[0].col);
  TEST_ASSERT_EQUAL(1, game.moves[0].row);

  TEST_ASSERT_EQUAL(1, game.moves[1].col);
  TEST_ASSERT_EQUAL(2, game.moves[1].row);

  TEST_ASSERT_EQUAL(2, game.moves[2].col);
  TEST_ASSERT_EQUAL(0, game.moves[2].row);

  for (int move = moves_given; move < MAX_MOVES; move++)
    TEST_ASSERT_TRUE(move__is_empty(&game.moves[move]));
}

void add_move__new_game__sets_first_move(void)
{
  Game game;
  game__initialize(&game);
  Move move;
  move__create(&move, 1, 2);

  game__add_move(&game, &move);

  TEST_ASSERT_EQUAL(1, game.moves[0].col);
  TEST_ASSERT_EQUAL(2, game.moves[0].row);
  TEST_ASSERT_TRUE(move__is_empty(&game.moves[1]));
}

void add_move__ongoing_game__sets_first_non_empty_move(void)
{
  Game game;
  int moves_given = 3;
  game__load(&game, (char[][2]){{0, 1}, {1, 2}, {1, 0}}, moves_given);

  Move move;
  move__create(&move, 2, 1);

  game__add_move(&game, &move);

  TEST_ASSERT_EQUAL(1, game.moves[2].col);
  TEST_ASSERT_EQUAL(0, game.moves[2].row);
  TEST_ASSERT_EQUAL(2, game.moves[3].col);
  TEST_ASSERT_EQUAL(1, game.moves[3].row);
  TEST_ASSERT_TRUE(move__is_empty(&game.moves[4]));
}

void add_move__full_game__ignores_move(void)
{
  Game game;
  int moves_given = 9;
  game__load(&game, (char[][2]){{1, 1}, {0, 0}, {1, 0}, {1, 2}, {0, 1}, {2, 1}, {2, 0}, {0, 2}, {2, 2}}, moves_given);

  Move move;
  move__create(&move, 0, 0);

  game__add_move(&game, &move);

  TEST_ASSERT_EQUAL(2, game.moves[8].col);
  TEST_ASSERT_EQUAL(2, game.moves[8].row);
}

void count_moves__new_game__returns_0(void)
{
  Game game;
  game__initialize(&game);

  char result = game__count_moves(&game);

  TEST_ASSERT_EQUAL(0, result);
}

void count_moves__ongoing_game__returns_number_of_moves(void)
{
  Game game;
  game__load(&game, (char[][2]){{1, 1}, {1, 2}, {2, 1}}, 3);

  char result = game__count_moves(&game);

  TEST_ASSERT_EQUAL(3, result);
}

void count_moves__drawn_game__returns_max_game_length(void)
{
  Game game = game_stub__draw();

  char result = game__count_moves(&game);

  TEST_ASSERT_EQUAL(MAX_MOVES, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(initialize__sets_all_moves_to_empty);
  RUN_TEST(load__empty_game__sets_all_moves_to_empty);
  RUN_TEST(load__ongoing_game__sets_all_correct_moves);
  RUN_TEST(add_move__new_game__sets_first_move);
  RUN_TEST(add_move__ongoing_game__sets_first_non_empty_move);
  RUN_TEST(add_move__full_game__ignores_move);
  RUN_TEST(count_moves__new_game__returns_0);
  RUN_TEST(count_moves__ongoing_game__returns_number_of_moves);
  RUN_TEST(count_moves__drawn_game__returns_max_game_length);
  UNITY_END();

  return 0;
}
