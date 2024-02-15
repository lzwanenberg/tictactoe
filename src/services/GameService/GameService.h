#pragma once

#include <stdbool.h>

#include "../../types/Game.h"

void initialize_game(Game *game);
void load_game(Game *game, char moves[][2], int size);
