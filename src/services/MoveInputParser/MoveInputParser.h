#pragma once

#include <stdbool.h>

typedef struct
{
  bool is_successful;
  int col;
  int row;
} MoveInputParser_ParseResult;

void parse_move_input(const char *input, MoveInputParser_ParseResult *result);
