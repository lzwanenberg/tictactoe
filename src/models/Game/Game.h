#pragma once
#include "../../config.h"
#include "../Move/Move.h"

typedef struct
{
  Move moves[MAX_MOVES];
} Game;

// TODO move initializing logic etc.. to this model
char game__count_moves(Game *game);
