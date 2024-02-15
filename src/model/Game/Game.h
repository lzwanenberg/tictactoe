#pragma once
#include "../../config.h"
#include <stdbool.h>
#include "../GameState/GameState.h"

typedef struct
{
  char col;
  char row;
} Game_Move;

typedef struct
{
  int moves[MAX_MOVES];
} Game;

typedef enum
{
  GAME__MOVE_VALIDITY__VALID,
  GAME__MOVE_VALIDITY__INVALID_CELL_OCCUPIED,
  GAME__MOVE_VALIDITY__INVALID_FINISHED,
  GAME__MOVE_VALIDITY__INVALID_OUT_OF_BOUNDS
} Game_MoveValidity;

typedef struct
{
  Game_MoveValidity move_validity;
  GameState state;
} Game_MoveResult;

void initialize_game(Game *game);
Game_MoveResult attempt_make_move(Game *game, Game_Move *move);
