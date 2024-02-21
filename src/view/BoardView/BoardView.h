#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"

typedef struct
{
  int marker_slots[MAX_MOVES];
} BoardView;

void board_view__initialize(BoardView *board_view);
void board_view__render(BoardView *board_view, Board *board, char *buffer);
