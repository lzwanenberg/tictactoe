#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../config.h"
#include "../../types/Move.h"

bool moves_are_equal(Move *a, Move *b)
{
  return a->col == b->col && a->row == b->row;
}

void empty_move(Move *move)
{
  move->col = -1;
  move->row = -1;
}

bool is_empty_move(Move *move)
{
  return move->col == -1 || move->row == -1;
}
