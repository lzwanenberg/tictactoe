#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "MoveInputParser.h"
#include "../../config.h"

static void string_to_upper(char *str)
{
  while (*str)
  {
    *str = toupper((unsigned char)*str);
    str++;
  }
}

static void set_unsuccessful(MoveInputParser_ParseResult *result)
{
  result->is_successful = false;
  result->col = -1;
  result->row = -1;
}

static char extract_index(char chars[2], char zero_char)
{
  for (int i = 0; i < 2; i++)
  {
    char uppercase_char = toupper(chars[i]);
    int index = toupper(chars[i]) - zero_char;

    if (index >= 0 && index < BOARD_SIZE)
      return index;
  }

  return -1;
}

static char extract_col(char chars[2])
{
  return extract_index(chars, 'A');
}

static char extract_row(char chars[2])
{
  return extract_index(chars, '1');
}

void parse_move_input(const char *input, MoveInputParser_ParseResult *result)
{
  if (strlen(input) != 2)
  {
    set_unsuccessful(result);
    return;
  }

  char copy[2] = {input[0], input[1]};
  char col = extract_col(copy);
  char row = extract_row(copy);

  if (col < 0 || row < 0)
  {
    set_unsuccessful(result);
    return;
  }

  result->is_successful = true;
  result->col = col;
  result->row = row;
}
