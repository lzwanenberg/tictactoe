#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"
#include "BoardView.h"

#define BOARD_TEMPLATE \
  "   A   B   C \n"    \
  "1  ? | ? | ? \n"    \
  "  -----------\n"    \
  "2  ? | ? | ? \n"    \
  "  -----------\n"    \
  "3  ? | ? | ? \n"

#define TEMPLATE_SLOT_MARKER '?'
#define MARKER_EMPTY ' '
#define MARKER_X 'X'
#define MARKER_O 'O'

void board_view__find_marker_slots(int *slots, int offset);
char board_view__map_cell_to_marker(Board_Cell cell);
void board_view__process_cell(Board *board, int *slots, char *buffer, char slot_id, char col, char row);
void board_view__fill_marker_slots(Board *board, int *slots, char *buffer);

void board_view__initialize(BoardView *board_view, Board *board)
{
  board_view->board = board;
}

void board_view__render(BoardView *board_view, char *buffer)
{
  int slots[MAX_MOVES];
  int offset = (int)strlen(buffer);

  board_view__find_marker_slots(slots, offset);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, BOARD_TEMPLATE);
  board_view__fill_marker_slots(board_view->board, slots, buffer);
}

static void board_view__find_marker_slots(int *slots, int offset)
{
  char *template = BOARD_TEMPLATE;

  char current_char = *template;
  char index = 0;
  char slots_found = 0;

  while (template[index] != '\0')
  {
    if (template[index] == TEMPLATE_SLOT_MARKER)
    {
      slots[slots_found] = index + offset;
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

static void board_view__fill_marker_slots(Board *board, int *slots, char *buffer)
{
  char slot_id = 0;
  for (char row = 0; row < BOARD_SIZE; row++)
    for (char col = 0; col < BOARD_SIZE; col++)
      board_view__process_cell(board, slots, buffer, slot_id++, col, row);
}

static void board_view__process_cell(Board *board, int *slots, char *buffer, char slot_id, char col, char row)
{
  int slot = slots[slot_id];
  Board_Cell cell = board->cells[col][row];
  char marker = board_view__map_cell_to_marker(cell);
  buffer[slot] = marker;
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
