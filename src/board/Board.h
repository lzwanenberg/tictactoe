
#pragma once
#define BOARD_SIZE 3

enum CellValue
{
  CELL_VALUE_EMPTY,
  CELL_VALUE_X,
  CELL_VALUE_O
};

struct Board
{
  enum CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
