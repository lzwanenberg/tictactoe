#pragma once

#include <stdbool.h>

#include "../../types/Game.h"
#include "../../types/Move.h"

typedef enum
{
  GAME_STATE__WAIT_FOR_MOVE_P1,
  GAME_STATE__WAIT_FOR_MOVE_P2,
  GAME_STATE__P1_WON,
  GAME_STATE__P2_WON,
  GAME_STATE__DRAW
} GameStateService_Result;

GameStateService_Result analyze_game_status(Game *game);
