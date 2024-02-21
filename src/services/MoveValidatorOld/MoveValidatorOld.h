#pragma once

#include <stdbool.h>

#include "../../models/Game/Game.h"
#include "../../models/Move/Move.h"

/**
 * @brief Enumeration representing the result of validating a move.
 */
typedef enum
{
  /**< The move is valid. */
  MOVE_VALIDATOR_OLD__RESULT__VALID,

  /**< The cell for the move is already occupied. */
  MOVE_VALIDATOR_OLD__RESULT__INVALID_CELL_OCCUPIED,

  /**< The game has already finished. */
  MOVE_VALIDATOR_OLD__RESULT__INVALID_FINISHED,

  /**< The move is out of bounds of the game board. */
  MOVE_VALIDATOR_OLD__RESULT__INVALID_OUT_OF_BOUNDS
} MoveValidatorOld_Result;

/**
 * @brief Validates a move within the context of a game.
 *
 * @param game A pointer to the Game structure representing the current game state.
 * @param move A pointer to the Move structure representing the move to be validated.
 * @return The result of the move validation as a MoveValidatorOld_Result.
 */
MoveValidatorOld_Result move_validator_old__validate(Game *game, Move *move);
