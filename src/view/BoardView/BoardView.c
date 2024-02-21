#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"
#include "BoardView.h"

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

size_t calculate_character_position(size_t offset, int row, int column);
void set_character_at_position(char *buffer, size_t offset, int row_id, int col_id, char character);
void process_cell(Board *board, char *buffer, size_t offset, int row, int col);

void board_view__initialize(BoardView *board_view, Board *board)
{
  board_view->board = board;
}

void board_view__set_board(BoardView *board_view, Board *board)
{
  board_view->board = board;
}

void board_view__render(BoardView *board_view, char *buffer)
{
  size_t offset = strlen(buffer);

  strcat_s(buffer, OUTPUT_BUFFER_SIZE, EMPTY_BOARD);

  for (int row = 0; row < BOARD_SIZE; row++)
    for (int col = 0; col < BOARD_SIZE; col++)
      process_cell(board_view->board, buffer, offset, col, row);
}

static void process_cell(Board *board, char *buffer, size_t offset, int col, int row)
{
  Board_Cell cell_value = board->cells[col][row];

  if (cell_value == BOARD__CELL__EMPTY)
    return;

  const char marker = cell_value == BOARD__CELL__P1 ? MARKER_X : MARKER_O;
  set_character_at_position(buffer, offset, col, row, marker);
}

static void set_character_at_position(char *buffer, size_t offset, int col_id, int row_id, char character)
{
  size_t position = calculate_character_position(offset, col_id, row_id);
  buffer[position] = character;
}

static size_t calculate_character_position(size_t offset, int column, int row)
{
  return offset +
         HEADER_ROW_LENGTH +
         ROW_OFFSET_LENGTH +
         (column * (SEPARATOR_LENGTH + 1)) +
         (row * (ROW_LENGTH + 1));
}
