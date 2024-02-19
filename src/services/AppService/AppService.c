#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AppService.h"
#include "../../config.h"

#include "../../view/GameView/GameView.h"
#include "../../view/BoardView/BoardView.h"
#include "../InputBuffer/InputBuffer.h"

void app_service__initialize(AppService *app)
{
  app->is_running = true;

  game__initialize(&app->game);
  input_buffer__initialize(&app->input_buffer);
  game_view__initialize(&app->view);
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
    app->view.input_error = "Invalid input.";
    app->view.message = "Todo: recalculate message";
    return;

  case INPUT_BUFFER__READ_RESULT__OK:
    app->view.message = "Todo: recalculate message2";
    return;
  }
}

void app_service__render(AppService *app, char *buffer)
{
  buffer[0] = '\0';
  game_view__render(&app->view, buffer);
}
