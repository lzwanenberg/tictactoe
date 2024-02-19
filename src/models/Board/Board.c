#pragma once

#include "../../config.h"
#include "../Game/Game.h"
#include "../Move/Move.h"
#include "Board.h"

void board__add_move(Board *board, Move *move, int move_id);

void board__initialize(Board *board)
{
  for (int col = 0; col < BOARD_SIZE; col++)
    for (int row = 0; row < BOARD_SIZE; row++)
      board->cells[col][row] = BOARD__CELL__EMPTY;
}

void board__update(Board *board, Game *game)
{
  board__initialize(board);
  for (int move_id = 0; move_id < MAX_MOVES; move_id++)
    board__add_move(board, &game->moves[move_id], move_id);
}

static void board__add_move(Board *board, Move *move, int move_id)
{
  if (move__is_empty(move))
    return;

  Board_Cell status = move_id % 2 == 0
                          ? BOARD__CELL__P1
                          : BOARD__CELL__P2;

  board->cells[move->col][move->row] = status;
}
