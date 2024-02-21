#pragma once
#include "../../config.h"
#include "../Move/Move.h"

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
 * @brief Initializes a Tic Tac Toe board
 *
 * @param board Pointer to the Board structure to initialize.
 */
void board__initialize(Board *board);

/**
 * @brief Reset the Tic Tac Toe board, setting all cells to empty
 *
 * @param board Pointer to the Board structure that will be emptied.
 */
void board__clear(Board *board);

/**
 * @brief Count the number of cells that are not empty
 *
 * Count the number of cells that are not empty, so the number of cells that
 * either contain a marker of player one or two.
 *
 * @param board Pointer to the Board structure
 * @return The number of cells that are non-empty
 */
char board__count_non_empty_cells(Board *board);

/**
 * @brief Load a number of moves
 *
 * The moves are assumed to be in the order that the moves are made. This means
 * that moves with an even index are assumed to have been made by player 1, while
 * the odd moves are assumed to have been made by player 2.
 *
 * @param board Pointer to the Board structure that will be modified
 * @param moves The moves that will be loaded
 * @param number_of_moves The number of moves that are in the given array
 */
void board__load(Board *board, char moves[][2], int number_of_moves);

/**
 * @brief Add a move to the board
 *
 * @param board Pointer to the Board structure to which the move will be added
 * @param move The move that will be added
 *
 */
void board__add_move(Board *board, Move *move);
