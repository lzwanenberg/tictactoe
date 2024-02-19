#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AppService.h"
#include "../../config.h"

#include "../../view/GameView/GameView.h"
#include "../../view/BoardView/BoardView.h"
#include "../../view/BoardView/BoardViewMapper/BoardViewMapper.h"
#include "../../view/BoardView/BoardRenderer/BoardRenderer.h"
#include "../InputBuffer/InputBuffer.h"

void app_service__initialize(AppService *app)
{
  app->is_running = true;

  game__initialize(&app->game);
  input_buffer__initialize(&app->input_buffer);
}

void app_service__receive_input(AppService *app, char *input)
{
  InputBuffer_ReadResult result = input_buffer__read(&app->input_buffer, input);

  switch (result)
  {
  case INPUT_BUFFER__READ_RESULT__OVERFLOWING:
    return;

  case INPUT_BUFFER__READ_RESULT__OVERFLOWN:
    // set_message(app, "Invalid input");
    return;

  case INPUT_BUFFER__READ_RESULT__OK:
    // TODO
    return;
  }
}

void app_service__render(AppService *app, char *buffer)
{
  buffer[0] = '\0';

  GameView game_view = (GameView){
      .input_error = "Hello this is an error",
      .message = "Enter move for player 1:"};

  game_view__render(&game_view, buffer);
}
