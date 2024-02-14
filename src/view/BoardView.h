#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO remove dependency
#include "../board/Board.h"

struct BoardView
{
  enum CellValue cells[BOARD_SIZE][BOARD_SIZE];
};
