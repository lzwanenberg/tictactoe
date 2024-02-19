#pragma once

#include "../BoardView.h"

/**
 * @brief Renders the board view into the provided buffer.
 *
 * Fills the provided buffer with the string representation of the board.
 *
 * @param board Pointer to the BoardView structure representing the game board.
 * @param buffer Pointer to the character buffer where the board view will be rendered.
 *               The buffer must be preallocated by the caller and have a size of at least
 *               BOARD_STRING_SIZE.
 */
void render_board_view(BoardView *board, char *buffer);
