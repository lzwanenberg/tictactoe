#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3

enum BoardView_CellValue
{
  BOARD_VIEW__CELL_EMPTY,
  BOARD_VIEW__CELL_X,
  BOARD_VIEW__CELL_O
};

struct BoardView
{
  enum BoardView_CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
