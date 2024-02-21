#pragma once

#include "../../models/Game/Game.h"
#include "../../models/Board/Board.h"
#include "../BoardView/BoardView.h"

typedef struct
{
  BoardView board_view;
  Board board;
  char *error;
  char *message;
} GameView;

void game_view__initialize(GameView *game_view);
void game_view__render(GameView *game_view, char *buffer);
