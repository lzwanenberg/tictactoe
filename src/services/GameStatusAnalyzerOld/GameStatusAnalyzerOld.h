#pragma once

#include <stdbool.h>
#include "../../models/Game/Game.h"
#include "../../models/Move/Move.h"

/**
 * @brief Enumeration representing possible results of game status analysis.
 */
typedef enum
{
  /**< Waiting for Player 1 to make a move. */
  GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1,

  /**< Waiting for Player 2 to make a move. */
  GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2,

  /**< Player 1 has won the game. */
  GAME_STATUS_SERVICE__RESULT__P1_WON,

  /**< Player 2 has won the game. */
  GAME_STATUS_SERVICE__RESULT__P2_WON,

  /**< The game is a draw. */
  GAME_STATUS_SERVICE__RESULT__DRAW
} GameStatusAnalyzerOld_Result;

/**
 * @brief Analyzes the current state of the game and determines the result.
 *
 * @param game A pointer to the Game structure representing the current game state.
 * @return The result of the game status analysis as a GameStatusAnalyzerOld_Result.
 */
GameStatusAnalyzerOld_Result game_status_analyzer_old__analyze(Game *game);
