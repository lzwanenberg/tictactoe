#pragma once

#include "../../config.h"
#include "Game.h"
#include "../Move/Move.h"

void game__initialize(Game *game)
{
  for (int i = 0; i < MAX_MOVES; i++)
  {
    move__initialize(&game->moves[i]);
  }
}

void game__load(Game *game, char moves[][2], int size)
{
  game__initialize(game);
  for (int i = 0; i < size; i++)
  {
    char col = moves[i][0];
    char row = moves[i][1];

    move__set(&game->moves[i], col, row);
  }
}

void game__add_move(Game *game, Move *move)
{
  int move_id = game__count_moves(game);

  if (move_id < MAX_MOVES)
    move__set(&game->moves[move_id], move->col, move->row);
}

char game__count_moves(Game *game)
{
  Move *current_move = game->moves;
  char count = 0;

  while (!move__is_empty(current_move++) && count < MAX_MOVES)
    count++;

  return count;
}
