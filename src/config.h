#pragma once

/**
 * @brief Number of columns/rows in a Tic Tac Toe game
 */
#define BOARD_SIZE 3

/**
 * @brief Number of maximum moves that can be made in game of Tic Tac Toe
 */
#define MAX_MOVES (BOARD_SIZE * BOARD_SIZE)

/**
 * @brief Size of the maximum amount of input that can be handled.
 *
 * Any input provided by the user that exceeds this size will be considered
 * invalid input.
 */
#define INPUT_BUFFER_SIZE 16

/**
 * @brief Size of the maximum amount of output
 *
 * This upperbound should be higher than all the characters that are required
 * to render a single frame of the game, including the title, the board and
 * (error) messages.
 */
#define OUTPUT_BUFFER_SIZE 2048
