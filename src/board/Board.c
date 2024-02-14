
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

struct Board create_empty_board()
{
  struct Board board;

  for (int i = 0; i < BOARD_SIZE; ++i)
  {
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
      board.cells[i][j] = CELL_VALUE_EMPTY;
    }
  }

  return board;
}
