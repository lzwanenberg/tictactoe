#pragma once

// #include "../Game/Game.h"

typedef enum
{
  GAME_STATE__WAIT_FOR_MOVE_P1,
  GAME_STATE__WAIT_FOR_MOVE_P2,
  GAME_STATE__P1_WON,
  GAME_STATE__P2_WON,
  GAME_STATE__DRAW
} GameState;

GameState calculate_game_state();
// GameState calculate_game_state(Game *game);
