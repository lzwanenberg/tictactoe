#pragma once

#include "../../config.h"
#include "Game.h"
#include "../Move/Move.h"

char game__count_moves(Game *game)
{
  Move *current_move = game->moves;
  char count = 0;

  while (!move__is_empty(current_move++) && count < MAX_MOVES)
    count++;

  return count;
}