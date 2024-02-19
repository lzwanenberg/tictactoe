#pragma once

#include "../../models/Game/Game.h"

typedef struct
{
  char *input_error;
  char *message;
} GameView;

void game_view__initialize(GameView *game_view);
void game_view__render(GameView *game_view, char *buffer);
