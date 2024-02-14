#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../board/Board.c"

struct BoardView
{
  enum CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
