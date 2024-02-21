#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AppService.h"
#include "../../config.h"

#include "../../view/GameView/GameView.h"
#include "../../view/BoardView/BoardView.h"
#include "../InputBuffer/InputBuffer.h"
#include "../MoveInputParser/MoveInputParser.h"
#include "../MoveValidator/MoveValidator.h"

void clean_input(char *input)
{
  size_t length = strlen(input);

  if (length > 0 && input[length - 1] == '\n')
    input[length - 1] = '\0';
}

void app_service__initialize(AppService *app)
{
  app->is_running = true;

  game__initialize(&app->game);
  input_buffer__initialize(&app->input_buffer);
  game_view__initialize(&app->view);
}

static char *app_service__calculate_message(AppService *app)
{
  return "TODO: calculate message";
}

static void app_service__attempt_make_move(AppService *app, Move *move)
{
  MoveValidator_Result result = move_validator__validate(&app->game, move);

  if (result == MOVE_VALIDATOR__RESULT__VALID)
    game__add_move(&app->game, move);
  else
    app->view.error = "Invalid move.";
  app->view.message = "this";
}

static void app_service__process_input(AppService *app, char *input)
{
  clean_input(input);
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
