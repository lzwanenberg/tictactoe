#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../models/Board/Board.h"
#include "BoardView.h"

#define BOARD_TEMPLATE \
  "   A   B   C \n"    \
  "1  ? | ? | ? \n"    \
  "  -----------\n"    \
  "2  ? | ? | ? \n"    \
  "  -----------\n"    \
  "3  ? | ? | ? \n"

#define BOARD_TEMPLATE_SIZE sizeof(BOARD_TEMPLATE)

#define TEMPLATE_SLOT_MARKER '?'
#define MARKER_EMPTY ' '
#define MARKER_X 'X'
#define MARKER_O 'O'

void board_view__cache_indented_template(BoardView *board_view, char *margin_left);
void board_view__cache_marker_slots(BoardView *board_view);
char board_view__map_cell_to_marker(Board_Cell cell);
void board_view__process_cell(BoardView *board_view, Board *board, char *buffer, int offset, char slot_id, char col, char row);
void board_view__fill_marker_slots(BoardView *board_view, Board *board, char *buffer, int offset);

void board_view__initialize(BoardView *board_view, char *margin_left)
{
  board_view__cache_indented_template(board_view, margin_left);
  board_view__cache_marker_slots(board_view);
}

void board_view__render(BoardView *board_view, Board *board, char *buffer)
{
  int offset = (int)strlen(buffer);

  strcat_s(buffer, OUTPUT_BUFFER_SIZE, board_view->view_template);
  board_view__fill_marker_slots(board_view, board, buffer, offset);
}

static void board_view__cache_marker_slots(BoardView *board_view)
{
  char index = 0;
  char slots_found = 0;

  while (board_view->view_template[index] != '\0')
  {
    if (board_view->view_template[index] == TEMPLATE_SLOT_MARKER)
    {
      board_view->marker_slots[slots_found] = index;
      slots_found++;
    }

    index++;
  }

  if (slots_found != MAX_MOVES)
  {
    fprintf(stderr,
            "Error: invalid template - wrong number of template slot markers, expected: %i, got %i.",
            MAX_MOVES,
            slots_found);
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

static void board_view__cache_indented_template(BoardView *board_view, char *margin_left)
{
  char *unindented_template = strdup(BOARD_TEMPLATE);
  int size = sizeof(board_view->view_template);
  char *line;
  char *next_line = NULL;

  board_view->view_template[0] = '\0';
  line = strtok_s(unindented_template, "\n", &next_line);

  while (line != NULL)
  {
    strcat_s(board_view->view_template, size, margin_left);
    strcat_s(board_view->view_template, size, line);
    strcat_s(board_view->view_template, size, "\n");
    line = strtok_s(NULL, "\n", &next_line);
  }
}
