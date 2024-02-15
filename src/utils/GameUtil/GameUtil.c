#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../config.h"
#include "../../types/Game.h"
#include "../../types/Move.h"
#include "../MoveUtil/MoveUtil.h"

char count_number_of_moves(Game *game)
{
  Move *current_move = game->moves;
  char count = 0;

  while (!is_empty_move(current_move++) && count < MAX_MOVES)
    count++;

  return count;
}
