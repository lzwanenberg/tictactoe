#pragma once

#include <stdbool.h>
#include "../../config.h"
#include "../../models/Game/Game.h"
#include "../InputBuffer/InputBuffer.h"
#include "../../view/GameView/GameView.h"

typedef struct
{
  Game game;
  InputBuffer input_buffer;
  GameView view;
  bool is_running;
} AppService;

void app_service__initialize(AppService *app);
void app_service__receive_input(AppService *app, char *input);
void app_service__render(AppService *app, char *output);
