#pragma once

#include <stdbool.h>

typedef struct
{
  char col;
  char row;
} Move;

Move create_empty_move();
bool is_empty_move(Move *move);
Move create_move(int col, int row);
