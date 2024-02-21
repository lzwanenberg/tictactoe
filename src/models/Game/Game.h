#pragma once
#include "../../config.h"
#include "../Move/Move.h"

/**
 * @brief Structure representing a game of Tic Tac Toe by a sequence of moves
 */
typedef struct
{
  Move moves[MAX_MOVES]; /**< Array of moves in the game. */
} Game;

/**
 * @brief Initializes a game board by setting all moves to empty moves
 *
 * @param game A pointer to the Game structure to be initialized.
 */
void game__initialize(Game *game);

/**
 * @brief Loads an array of moves into the Game structure.
 *
 * @param game A pointer to the Game structure to which moves will be loaded.
 * @param moves An array of move descriptions, where each move is represented as a pair of characters.
 * @param size The number of moves to load into the Game.
 */
void game__load(Game *game, char moves[][2], int size);

/**
 * @brief Adds a new move to the Game structure. If the maximum amount of moves has been reached,
 * the move will be ignored.
 *
 * @param game A pointer to the Game structure to which the move will be added.
 * @param move A pointer to the Move structure representing the new move to add.
 */
void game__add_move(Game *game, Move *move);

/**
 * @brief Counts the number of non-empty moves currently in the Game structure.
 *
 * @param game A pointer to the Game structure to be counted.
 * @return The number of non-empty moves in the Game structure.
 */
char game__count_moves(Game *game);
