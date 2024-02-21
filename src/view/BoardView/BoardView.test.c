#pragma once

#include <stdio.h>
#include "unity.h"

#include "../../models/Board/Board.h"
#include "BoardView.h"

#define _ BOARD_VIEW__CELL_EMPTY
#define X BOARD_VIEW__CELL_P1
#define O BOARD_VIEW__CELL_P2

void setUp(void)
{
}

void tearDown(void)
{
}

void render__empty_board__renders_correctly(void)
{
  Board board;
  BoardView board_view;

  board__initialize(&board);
  board_view__initialize(&board_view, "  ");

  char buffer[OUTPUT_BUFFER_SIZE];
  buffer[0] = '\0';

  board_view__render(&board_view, &board, buffer);

  char *expected =
      "     A   B   C \n"
      "  1    |   |   \n"
      "    -----------\n"
      "  2    |   |   \n"
      "    -----------\n"
      "  3    |   |   \n";

  TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

void render__non_empty_board__renders_correctly(void)
{
  char buffer[OUTPUT_BUFFER_SIZE];
  buffer[0] = '\0';

  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "My Tic Tac Toe Game\n");

  Board board;
  BoardView board_view;

  char moves[][2] = {{1, 0}, {1, 1}, {0, 2}, {0, 1}, {2, 1}, {2, 0}};

  board__initialize(&board);
  board__load(&board, moves, 6);

  board_view__initialize(&board_view, "  ");
  board_view__render(&board_view, &board, buffer);

  char *expected =
      "My Tic Tac Toe Game\n"
      "     A   B   C \n"
      "  1    | X | O \n"
      "    -----------\n"
      "  2  O | O | X \n"
      "    -----------\n"
      "  3  X |   |   \n";

  TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(render__empty_board__renders_correctly);
  RUN_TEST(render__non_empty_board__renders_correctly);
  UNITY_END();

  return 0;
}
