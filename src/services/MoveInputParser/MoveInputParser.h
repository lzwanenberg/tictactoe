#pragma once

#include <stdbool.h>

typedef struct
{
  bool is_successful;
  int col;
  int row;
} MoveInputParser_ParseResult;

void move_input_parser__parse(const char *input, MoveInputParser_ParseResult *result);
