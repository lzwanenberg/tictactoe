#pragma once
#include "../../config.h"
#include "../Game/Game.h"

/**
 * @brief Enumeration representing the possible states of a cell in a board view.
 */
typedef enum
{
  /**< The cell is empty. */
  BOARD__CELL__EMPTY,

  /**< The cell is occupied by player 1. */
  BOARD__CELL__P1,

  /**< The cell is occupied by player 2. */
  BOARD__CELL__P2,
} Board_Cell;

/**
 * @brief Structure representing a board view in a Tic Tac Toe game.
 */
typedef struct
{
  /**
   * 2D array representing the cells of the board.
   */
  Board_Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

void board__initialize(Board *board);
void board__update(Board *board, Game *game);
