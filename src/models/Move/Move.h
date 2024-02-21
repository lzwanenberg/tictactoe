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

/**
 * @brief Initializes a move by setting the column and row to empty values.
 *
 * @param move A pointer to the Move structure to be initialized.
 */
void move__initialize(Move *move);

/**
 * @brief Creates a move with specified column and row values.
 *
 * @param move A pointer to the Move structure to be created.
 * @param col The zero-based column of the move.
 * @param row The zero-based row of the move.
 */
void move__create(Move *move, char col, char row);

/**
 * @brief Sets the column and row of a move to specified values.
 *
 * @param move A pointer to the Move structure to be modified.
 * @param col The new zero-based column of the move.
 * @param row The new zero-based row of the move.
 */
void move__set(Move *move, char col, char row);

/**
 * @brief Empties the values of a move.
 *
 * @param move A pointer to the Move structure to be emptied.
 */
void move__empty(Move *move);

/**
 * @brief Checks if two moves are equal.
 *
 * @param a A pointer to the first Move structure.
 * @param b A pointer to the second Move structure.
 * @return true if the moves are equal, false otherwise.
 */
bool move__is_equal(Move *a, Move *b);

/**
 * @brief Checks if a move is empty
 *
 * @param move A pointer to the Move structure to be checked.
 * @return true if the move is empty, false otherwise.
 */
bool move__is_empty(Move *move);
