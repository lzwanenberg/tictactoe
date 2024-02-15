#pragma once

#include <stdbool.h>
#include "../../types/Move.h"

bool moves_are_equal(Move *a, Move *b);
void empty_move(Move *move);
bool is_empty_move(Move move);
