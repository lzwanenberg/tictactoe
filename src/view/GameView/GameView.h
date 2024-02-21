#pragma once

#include "../../models/Game/Game.h"
#include "../../models/Board/Board.h"
#include "../BoardView/BoardView.h"

/**
 * @brief Represents the view of the Tic Tac Toe game for rendering purposes.
 */
typedef struct
{
  /**< The view of the actual board. */
  BoardView board_view;

  /**< The underlying board structure. */
  Board board;

  /**< Error message, if any. */
  char *error;

  /**< General message, if any. */
  char *message;

  /**< White space that will be added before each line*/
  char *margin_left;
} GameView;

/**
 * @brief Initializes a GameView with default values.
 *
 * This function initializes a GameView structure with default values,
 * including the board view and the underlying game board.
 *
 * @param game_view A pointer to the GameView structure to be initialized.
 */
void game_view__initialize(GameView *game_view, char *margin_left);

/**
 * @brief Resets a GameView to its initial state.
 *
 * This function resets the GameView structure and clears (error)
 * messages
 *
 * @param game_view A pointer to the GameView structure to be reset.
 */
void game_view__reset(GameView *game_view);

/**
 * @brief Renders the current state of the Tic Tac Toe game view.
 *
 * This function renders the current state of the Tic Tac Toe game,
 * including the title, game board view, any error message, and a general message.
 * The rendered view is stored in the provided buffer.
 *
 * @param game_view A pointer to the GameView structure representing the game view.
 * @param buffer A character buffer to store the rendered game view.
 */
void game_view__render(GameView *game_view, char *buffer);
