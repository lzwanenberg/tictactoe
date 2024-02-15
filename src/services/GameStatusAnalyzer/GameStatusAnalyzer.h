#pragma once

#include <stdbool.h>

#include "../../types/Game.h"
#include "../../types/Move.h"

typedef enum
{
  GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1,
  GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2,
  GAME_STATUS_SERVICE__RESULT__P1_WON,
  GAME_STATUS_SERVICE__RESULT__P2_WON,
  GAME_STATUS_SERVICE__RESULT__DRAW
} GameStatusService_Result;

GameStatusService_Result analyze_game_status(Game *game);
