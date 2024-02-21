#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "AppService.h"
#include "../../config.h"

#include "../../view/GameView/GameView.h"
#include "../../view/BoardView/BoardView.h"
#include "../InputBuffer/InputBuffer.h"
#include "../MoveInputParser/MoveInputParser.h"
#include "../MoveValidator/MoveValidator.h"
#include "../GameStatusAnalyzer/GameStatusAnalyzer.h"

char *app_service__calculate_message(AppService *app);
void app_service__attempt_make_move(AppService *app, Move *move);
void app_service__process_input(AppService *app, char *input);
void app_service__process_input_ongoing_game(AppService *app, char *input);
void app_service__process_input_finished_game(AppService *app, char *input);
void string_to_lower(char *str);
void clean_input(char *input);

void app_service__initialize(AppService *app)
{
  app->is_running = true;

  game__initialize(&app->game);
  input_buffer__initialize(&app->input_buffer);
  game_view__initialize(&app->view);

  app->view.message = app_service__calculate_message(app);
}

void app_service__receive_input(AppService *app, char *input)
{
  game_view__initialize(&app->view);
  InputBuffer_ReadResult result = input_buffer__read(&app->input_buffer, input);

  switch (result)
  {
  case INPUT_BUFFER__READ_RESULT__OVERFLOWING:
    return;

  case INPUT_BUFFER__READ_RESULT__OVERFLOWN:
    app->view.error = "Invalid input.";
    app->view.message = app_service__calculate_message(app);
    return;

  case INPUT_BUFFER__READ_RESULT__OK:
    app_service__process_input(app, input);
    app->view.message = app_service__calculate_message(app);
    return;
  }
}

void app_service__render(AppService *app, char *buffer)
{
  buffer[0] = '\0';
  game_view__render(&app->view, buffer);
}

static char *app_service__calculate_message(AppService *app)
{
  GameStatusAnalyzer_Result result =
      game_status_analyzer__analyze(&app->game);

  switch (result)
  {
  case GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1:
    return "Enter your move (P1):";

  case GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2:
    return "Enter your move (P2):";

  case GAME_STATUS_SERVICE__RESULT__P1_WON:
    return "P1 won! Play again? (y/n)";

  case GAME_STATUS_SERVICE__RESULT__P2_WON:
    return "P2 won! Play again? (y/n)";

  case GAME_STATUS_SERVICE__RESULT__DRAW:
    return "It's a draw! Play again? (y/n)";

  default:
    return NULL;
  }
}

static void app_service__process_input(AppService *app, char *input)
{
  clean_input(input);
  GameStatusAnalyzer_Result result =
      game_status_analyzer__analyze(&app->game);

  bool is_ongoing = result == GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1 || result == GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2;

  if (is_ongoing)
    app_service__process_input_ongoing_game(app, input);
  else
    app_service__process_input_finished_game(app, input);
}

static void app_service__process_input_ongoing_game(AppService *app, char *input)
{
  MoveInputParser_ParseResult result;
  move_input_parser__parse(input, &result);

  if (!result.is_successful)
  {
    app->view.error = "Invalid input.";
    return;
  }

  Move move = (Move){
      .col = result.col,
      .row = result.row};

  app_service__attempt_make_move(app, &move);
}

static void app_service__process_input_finished_game(AppService *app, char *input)
{
  string_to_lower(input);

  if (strcmp(input, "y") == 0)
    game__initialize(&app->game);
  else if (strcmp(input, "n") == 0)
    app->is_running = false;
  else
    app->view.error = "Invalid input.";
}

static void app_service__attempt_make_move(AppService *app, Move *move)
{
  MoveValidator_Result result = move_validator__validate(&app->game, move);

  if (result == MOVE_VALIDATOR__RESULT__VALID)
    game__add_move(&app->game, move);
  else
    app->view.error = "Invalid move.";
}

void string_to_lower(char *str)
{
  while (*str)
  {
    *str = tolower((unsigned char)*str);
    str++;
  }
}

static void clean_input(char *input)
{
  size_t length = strlen(input);

  if (length > 0 && input[length - 1] == '\n')
    input[length - 1] = '\0';
}
