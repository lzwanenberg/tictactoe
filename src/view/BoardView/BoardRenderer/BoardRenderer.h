#pragma once

#include "../BoardView.h"

/**
 * @brief Creates a buffer for representing the board as a string.
 *
 * Allocates memory for a character buffer to store the string representation
 * of the board.
 *
 * @return A pointer to the allocated buffer. Caller is responsible for freeing
 * the memory.
 */
char *create_board_string_buffer();

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
