#pragma once
#include <stdbool.h>
#include "Move.h"

void move__initialize(Move *move)
{
  move__empty(move);
}

void move__create(Move *move, char col, char row)
{
  move__set(move, col, row);
}

bool move__is_equal(Move *a, Move *b)
{
  return a->col == b->col && a->row == b->row;
}

void move__empty(Move *move)
{
  move->col = -1;
  move->row = -1;
}

void move__set(Move *move, char col, char row)
{
  move->col = col;
  move->row = row;
}

bool move__is_empty(Move *move)
{
  return move->col == -1 || move->row == -1;
}
