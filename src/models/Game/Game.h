#pragma once
#include "../../config.h"
#include "../Move/Move.h"

typedef struct
{
  Move moves[MAX_MOVES];
} Game;

void game__initialize(Game *game);
void game__load(Game *game, char moves[][2], int size);
char game__count_moves(Game *game);
