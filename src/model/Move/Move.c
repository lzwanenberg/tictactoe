#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"
#include "Move.h"

#define EMPTY_MOVE_CODE -1

Move create_empty_move()
{
  return (Move){.col = -1, .row = -1};
}

bool is_empty_move(Move *move)
{
  return move->col == -1 || move->row == -1;
}

Move create_move(int col, int row)
{
  return (Move){.col = col, .row = row};
}
