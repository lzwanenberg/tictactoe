#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../../config.h"
#include "BoardViewMapper.h"
#include "../../../models/Game/Game.h"
#include "../BoardView.h"

static void empty_board_view(BoardView *board_view)
{
  for (int row = 0; row < BOARD_SIZE; row++)
  {
    for (int col = 0; col < BOARD_SIZE; col++)
    {
      board_view->cells[row][col] = BOARD_VIEW__CELL_EMPTY;
    }
  }
}

static enum BoardView_CellValue get_cell_value(char move_id)
{
  return move_id % 2 == 0
             ? BOARD_VIEW__CELL_P1
             : BOARD_VIEW__CELL_P2;
}

void map_game_to_board_view(Game *game, BoardView *board_view)
{
  empty_board_view(board_view);

  char number_of_moves = game__count_moves(game);

  for (int move_id = 0; move_id < number_of_moves; move_id++)
  {
    char col = game->moves[move_id].col;
    char row = game->moves[move_id].row;

    board_view->cells[col][row] = get_cell_value(move_id);
  }
}
