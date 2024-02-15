#pragma once

#include <stdbool.h>
#include "../../types/Move.h"

bool moves_are_equal(Move *a, Move *b);
void empty_move(Move *move);
void set_move(Move *move, char col, char row);
Move create_move(char col, char row);
bool is_empty_move(Move *move);
