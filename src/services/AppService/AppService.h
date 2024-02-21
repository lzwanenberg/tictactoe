#pragma once

#include <stdbool.h>
#include "../../config.h"
#include "../../models/Game/Game.h"
#include "../InputBuffer/InputBuffer.h"
#include "../../view/GameView/GameView.h"

/**
 * @brief Represents an application service managing game state, user input, and rendering.
 */
typedef struct
{
  /**< The current state of the game. */
  Game game;

  /**< The buffer for user input. */
  InputBuffer input_buffer;

  /**< The view for rendering the game. */
  GameView view;

  /**< Flag indicating if the application is running. */
  bool is_running;
} AppService;

/**
 * @brief Initializes the application service by setting up initial states.
 *
 * @param app A pointer to the AppService structure to be initialized.
 */
void app_service__initialize(AppService *app);

/**
 * @brief Process user input
 *
 * @param app A pointer to the AppService structure.
 * @param input The user input string.
 */
void app_service__process_input(AppService *app, char *input);

/**
 * @brief Renders the current state of the game.
 *
 * @param app A pointer to the AppService structure.
 * @param output The output buffer for rendering the game view.
 */
void app_service__render(AppService *app, char *output);
