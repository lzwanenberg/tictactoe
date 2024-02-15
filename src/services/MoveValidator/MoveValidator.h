#pragma once

#include <stdbool.h>

#include "../../types/Game.h"
#include "../../types/Move.h"

typedef enum
{
  MOVE_VALIDATOR__RESULT__VALID,
  MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED,
  MOVE_VALIDATOR__RESULT__INVALID_FINISHED,
  MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS
} MoveValidator_Result;

MoveValidator_Result validate_move(Game *game, Move *move);