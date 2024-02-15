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

void load_game(Game *game, char moves[][2], int size)
{
  initialize_game(game);
  for (int i = 0; i < size; i++)
  {
    char row = moves[i][0];
    char col = moves[i][1];

    set_move(&game->moves[i], row, col);
  }
}
