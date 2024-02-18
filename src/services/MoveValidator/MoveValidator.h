#pragma once

#include <stdbool.h>

#include "../../models/Game/Game.h"
#include "../../models/Move/Move.h"

typedef enum
{
  MOVE_VALIDATOR__RESULT__VALID,
  MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED,
  MOVE_VALIDATOR__RESULT__INVALID_FINISHED,
  MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS
} MoveValidator_Result;

MoveValidator_Result move_validator__validate(Game *game, Move *move);
