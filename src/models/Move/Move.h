#pragma once

#include <stdbool.h>

/**
 * @brief Represents a move on a game board.
 */
typedef struct
{
  char col; /**< The zero-based column of the move. */
  char row; /**< The zero-based row of the move. */
} Move;
