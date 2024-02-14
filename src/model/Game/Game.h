#pragma once
#include "../../config.h"

typedef struct
{
  int row;
  int col;
} Game_Move;

typedef struct
{
  int current_move;
  Game_Move moves[MAX_MOVES];
} Game;

void initialize_game(Game *game);
