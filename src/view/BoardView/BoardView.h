#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3

/**
 * @brief Enumeration representing the possible states of a cell in a board view.
 */
enum BoardView_CellValue
{
  /**< The cell is empty. */
  BOARD_VIEW__CELL_EMPTY,

  /**< The cell is occupied by player 1. */
  BOARD_VIEW__CELL_P1,

  /**< The cell is occupied by player 2. */
  BOARD_VIEW__CELL_P2
};

/**
 * @brief Structure representing a board view in a Tic Tac Toe game.
 */
struct BoardView
{
  /**
   * 2D array representing the cells of the board.
   */
  enum BoardView_CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
