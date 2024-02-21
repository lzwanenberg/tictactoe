#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"
#include "../../models/Move/Move.h"
#include "../GameStatusAnalyzerOld/GameStatusAnalyzerOld.h"

#include "MoveValidatorOld.h"

static bool check_game_finished(Game *game)
{
  GameStatusAnalyzerOld_Result status = game_status_analyzer_old__analyze(game);

  return status == GAME_STATUS_SERVICE__RESULT__P1_WON ||
         status == GAME_STATUS_SERVICE__RESULT__P2_WON ||
         status == GAME_STATUS_SERVICE__RESULT__DRAW;
}

static bool is_out_of_bounds(Move *move)
{
  return move->col < 0 ||
         move->col >= BOARD_SIZE ||
         move->row < 0 ||
         move->row >= BOARD_SIZE;
}

static bool is_cell_occupied(Game *game, Move *move)
{
  for (int i = 0; i < MAX_MOVES; i++)
  {
    if (move__is_equal(&game->moves[i], move))
    {
      return true;
    }
  }

  return false;
}

MoveValidatorOld_Result move_validator_old__validate(Game *game, Move *move)
{
  if (check_game_finished(game))
    return MOVE_VALIDATOR_OLD__RESULT__INVALID_FINISHED;

  if (is_out_of_bounds(move))
    return MOVE_VALIDATOR_OLD__RESULT__INVALID_OUT_OF_BOUNDS;

  if (is_cell_occupied(game, move))
    return MOVE_VALIDATOR_OLD__RESULT__INVALID_CELL_OCCUPIED;

  return MOVE_VALIDATOR_OLD__RESULT__VALID;
}