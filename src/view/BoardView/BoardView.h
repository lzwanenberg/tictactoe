#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"

typedef struct
{
  Board *board;
} BoardView;

void board_view__initialize(BoardView *board_view, Board *board);
void board_view__set_board(BoardView *board_view, Board *board);
void board_view__render(BoardView *board_view, char *buffer);
