
#pragma once
#define BOARD_SIZE 3

enum Board_CellValue
{
  BOARD__CELL_VALUE_EMPTY,
  BOARD__CELL_VALUE_P1,
  BOARD__CELL_VALUE_P2
};

struct Board
{
  enum Board_CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
