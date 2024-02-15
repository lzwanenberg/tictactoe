#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"
#include "GameService.h"
#include "../../utils/MoveUtil/MoveUtil.h"

void initialize_game(Game *game)
{
  for (int i = 0; i < MAX_MOVES; i++)
  {
    empty_move(&game->moves[i]);
  }
}
