#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"
#include "../../models/Move/Move.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"

#include "MoveValidator.h"

static bool check_game_finished(Board *board)
{
  GameStatusAnalyzer_Result status = game_status_analyzer__analyze(board);

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

static bool is_cell_occupied(Board *board, Move *move)
{
  return board->cells[move->col][move->row] != BOARD__CELL__EMPTY;
}

MoveValidator_Result move_validator__validate(Board *board, Move *move)
{
  if (check_game_finished(board))
    return MOVE_VALIDATOR__RESULT__INVALID_FINISHED;

  if (is_out_of_bounds(move))
    return MOVE_VALIDATOR__RESULT__INVALID_OUT_OF_BOUNDS;

  if (is_cell_occupied(board, move))
    return MOVE_VALIDATOR__RESULT__INVALID_CELL_OCCUPIED;

  return MOVE_VALIDATOR__RESULT__VALID;
}