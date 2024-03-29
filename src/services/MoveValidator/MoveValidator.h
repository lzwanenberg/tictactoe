#pragma once

#include <stdbool.h>

#include "../../models/Board/Board.h"
#include "../../models/Move/Move.h"

/**
 * @brief Enumeration representing the result of validating a move.
 */
typedef enum
{
  /**< The move is valid. */
  MOVE_VALIDATOR__RESULT__VALID,

  /**< The cell for the move is already occupied. */
  MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED,

  /**< The game has already finished. */
  MOVE_VALIDATOR__RESULT__INVALID_FINISHED,

  /**< The move is out of bounds of the game board. */
  MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS
} MoveValidator_Result;

/**
 * @brief Validates a move within the context of a game.
 *
 * @param board A pointer to the Board structure representing the current game state.
 * @param move A pointer to the Move structure representing the move to be validated.
 * @return The result of the move validation as a MoveValidator_Result.
 */
MoveValidator_Result move_validator__validate(Board *board, Move *move);
