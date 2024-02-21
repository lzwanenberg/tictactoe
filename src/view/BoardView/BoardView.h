#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../config.h"
#include "../../models/Board/Board.h"

/**
 * @brief Represents a view of the game board for rendering purposes.
 */
typedef struct
{
  /**< Array of marker slots for rendering moves on the board. */
  int marker_slots[MAX_MOVES];
} BoardView;

/**
 * @brief Initializes a BoardView
 *
 * @param board_view A pointer to the BoardView structure to be initialized.
 */
void board_view__initialize(BoardView *board_view);

/**
 * @brief Renders the board view
 *
 * This function renders the current state of the game board with markers
 * placed in the appropriate marker slots. It generates a string representation
 * of the board view in the provided buffer.
 *
 * @param board_view A pointer to the BoardView structure representing the view.
 * @param board A pointer to the Board structure representing the game board.
 * @param buffer A character buffer to store the rendered board view.
 */
void board_view__render(BoardView *board_view, Board *board, char *buffer);
