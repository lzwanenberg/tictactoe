#pragma once

#include <stdbool.h>

#include "../../types/Game.h"

void game_service__initialize(Game *game);
void game_service__load_game(Game *game, char moves[][2], int size);
