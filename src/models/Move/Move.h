#pragma once

#include <stdbool.h>

typedef struct
{
  char col;
  char row;
} Move;

void move__initialize(Move *move);
void move__create(Move *move, char col, char row);
void move__set(Move *move, char col, char row);
void move__empty(Move *move);
bool move__is_equal(Move *a, Move *b);
bool move__is_empty(Move *move);
