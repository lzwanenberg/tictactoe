#pragma once
#include "../../config.h"
#include "../Game/Game.h"

/**
 * @brief Enumeration representing the possible states of a cell in a Tic Tac Toe board.
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
 * @brief Structure representing a Tic Tac Toe board.
 */
typedef struct
{
  /**
   * 2D array representing the cells of the Tic Tac Toe board.
   * Each cell can be empty or occupied by a player (Player 1 or Player 2).
   */
  Board_Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

/**
 * @brief Initializes a Tic Tac Toe board, setting all cells to EMPTY.
 *
 * @param board Pointer to the Board structure to initialize.
 */
void board__initialize(Board *board);

/**
 * @brief Updates the board based on the current state of the Tic Tac Toe game.
 *
 * This function takes a Board structure and a Game structure as inputs,
 * updating the board's cell states based on the moves made in the game.
 *
 * @param board Pointer to the Board structure to update.
 * @param game Pointer to the Game structure representing the Tic Tac Toe game.
 */
void board__update(Board *board, Game *game);
