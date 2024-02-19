#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "BoardRenderer.h"
#include "../BoardView.h"
#include "../../../support/macros/safe_malloc.h"

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

static size_t calculate_character_position(int row, int column);
static void set_character_at_position(char *buffer, int row_id, int col_id, char character);
static void process_cell(BoardView *board, char *buffer, int row, int col);

void render_board_view(BoardView *board, char *buffer)
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

static void process_cell(BoardView *board, char *buffer, int row, int col)
{
  enum BoardView_CellValue cell_value = board->cells[row][col];

  if (cell_value == BOARD_VIEW__CELL_EMPTY)
    return;

  const char marker = cell_value == BOARD_VIEW__CELL_P1 ? MARKER_X : MARKER_O;
  set_character_at_position(buffer, row, col, marker);
}

static void set_character_at_position(char *buffer, int row_id, int col_id, char character)
{
  size_t position = calculate_character_position(row_id, col_id);
  buffer[position] = character;
}

static size_t calculate_character_position(int row, int column)
{
  return HEADER_ROW_LENGTH +
         ROW_OFFSET_LENGTH +
         (column * (SEPARATOR_LENGTH + 1)) +
         (row * (ROW_LENGTH + 1));
}
