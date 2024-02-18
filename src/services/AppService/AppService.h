#pragma once

#include <stdbool.h>
#include "../../config.h"
#include "../../models/Game/Game.h"
#include "../InputBuffer/InputBuffer.h"

#define MAX_MESSAGE_SIZE 128

typedef struct
{
  InputBuffer input_buffer;
  bool is_running;
  Game game;
  char message[MAX_MESSAGE_SIZE];
} AppState;

void app_service__initialize(AppState *state);
void app_service__receive_input(AppState *state, char *input);
void app_service__render(AppState *app, char *output);
