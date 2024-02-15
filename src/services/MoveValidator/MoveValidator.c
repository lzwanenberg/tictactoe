#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"
#include "../../utils/MoveUtil/MoveUtil.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"

#include "MoveValidator.h"

static bool has_game_finished(Game *game)
{
  GameStatusService_Result status = analyze_game_status(game);

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
  return false;
}

MoveValidator_Result validate_move(Game *game, Move *move)
{
  if (has_game_finished(game))
    return MOVE_VALIDATOR__RESULT__INVALID_FINISHED;

  if (is_out_of_bounds(move))
    return MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS;

  if (is_cell_occupied(game, move))
    return MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED;

  return MOVE_VALIDATOR__RESULT__VALID;
}