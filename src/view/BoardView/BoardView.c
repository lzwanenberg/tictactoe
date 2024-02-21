#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"
#include "BoardView.h"

#define BOARD_TEMPLATE               \
  VIEW_MARGIN_LEFT                   \
  "   A   B   C \n" VIEW_MARGIN_LEFT \
  "1  ? | ? | ? \n" VIEW_MARGIN_LEFT \
  "  -----------\n" VIEW_MARGIN_LEFT \
  "2  ? | ? | ? \n" VIEW_MARGIN_LEFT \
  "  -----------\n" VIEW_MARGIN_LEFT \
  "3  ? | ? | ? \n"

#define TEMPLATE_SLOT_MARKER '?'
#define MARKER_EMPTY ' '
#define MARKER_X 'X'
#define MARKER_O 'O'

void board_view__cache_marker_slots(int *slots);
char board_view__map_cell_to_marker(Board_Cell cell);
void board_view__process_cell(BoardView *board_view, Board *board, char *buffer, int offset, char slot_id, char col, char row);
void board_view__fill_marker_slots(BoardView *board_view, Board *board, char *buffer, int offset);

void board_view__initialize(BoardView *board_view)
{
  board_view__cache_marker_slots(board_view->marker_slots);
}

void board_view__render(BoardView *board_view, Board *board, char *buffer)
{
  int offset = (int)strlen(buffer);

  strcat_s(buffer, OUTPUT_BUFFER_SIZE, BOARD_TEMPLATE);
  board_view__fill_marker_slots(board_view, board, buffer, offset);
}

static void board_view__cache_marker_slots(int *slots)
{
  char *template = BOARD_TEMPLATE;

  char current_char = *template;
  char index = 0;
  char slots_found = 0;

  while (template[index] != '\0')
  {
    if (template[index] == TEMPLATE_SLOT_MARKER)
    {
      slots[slots_found] = index;
      slots_found++;
    }

    index++;
  }

  if (slots_found != MAX_MOVES)
  {
    fprintf(stderr, "Error: invalid template - wrong number of template slot markers.");
    exit(EXIT_FAILURE);
  }
}

static void board_view__fill_marker_slots(BoardView *board_view, Board *board, char *buffer, int offset)
{
  char slot_id = 0;
  for (char row = 0; row < BOARD_SIZE; row++)
    for (char col = 0; col < BOARD_SIZE; col++)
      board_view__process_cell(board_view, board, buffer, offset, slot_id++, col, row);
}

static void board_view__process_cell(BoardView *board_view, Board *board, char *buffer, int offset, char slot_id, char col, char row)
{
  int slot = board_view->marker_slots[slot_id];
  Board_Cell cell = board->cells[col][row];
  char marker = board_view__map_cell_to_marker(cell);
  buffer[slot + offset] = marker;
}

static char board_view__map_cell_to_marker(Board_Cell cell)
{
  switch (cell)
  {
  case BOARD__CELL__P1:
    return MARKER_X;

  case BOARD__CELL__P2:
    return MARKER_O;

  default:
    return MARKER_EMPTY;
  }
}
