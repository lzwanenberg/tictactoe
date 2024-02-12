#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../board/Board.c"

#define HEADER_ROW "   A   B   C\n"
#define EMPTY_ROW "  _ | _ | _\n"

#define ROW_OFFSET_LENGTH strlen("1  ")
#define SEPARATOR_LENGTH strlen(" | ")
#define HEADER_ROW_LENGTH strlen(HEADER_ROW)
#define ROW_LENGTH strlen(EMPTY_ROW)

#define EMPTY_BOARD HEADER_ROW "1" EMPTY_ROW "2" EMPTY_ROW "3" EMPTY_ROW

#define BOARD_STRING_SIZE sizeof(EMPTY_BOARD)

#define MARKER_X 'X'
#define MARKER_O 'O'

static size_t calculate_character_position(int row, int column)
{
  return HEADER_ROW_LENGTH +
         ROW_OFFSET_LENGTH +
         (column * (SEPARATOR_LENGTH + 1)) +
         (row * (ROW_LENGTH + 1));
}

static void set_character_at_position(char *buffer, int row_id, int col_id, char character)
{
  size_t position = calculate_character_position(row_id, col_id);
  buffer[position] = character;
}

char *create_board_string_buffer()
{
  char *buffer = malloc(BOARD_STRING_SIZE * sizeof(char));
  return buffer;
}

void process_cell(struct TicTacToeBoard *board, char *buffer, int row, int col)
{
  enum CellValue cell_value = board->cells[row][col];

  if (cell_value == CELL_VALUE_EMPTY)
    return;

  const char marker = cell_value == CELL_VALUE_X ? MARKER_X : MARKER_O;
  set_character_at_position(buffer, row, col, marker);
}

void board_to_string(struct TicTacToeBoard *board, char *buffer)
{
  strcpy_s(buffer, BOARD_STRING_SIZE, EMPTY_BOARD);

  for (int row = 0; row < BOARD_SIZE; row++)
  {
    for (int col = 0; col < BOARD_SIZE; col++)
    {
      process_cell(board, buffer, row, col);
    }
  }
}
