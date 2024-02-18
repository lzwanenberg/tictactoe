#pragma once

#include <stdbool.h>
#include "../../config.h"
#include "../../types/Game.h"
#include "../InputBuffer/InputBuffer.h"

#define MAX_MESSAGE_SIZE 128

typedef struct
{
  InputBuffer input_buffer;
  bool is_running;
  Game game;
  char message[MAX_MESSAGE_SIZE];
} AppState;

void initialize_app(AppState *state);
void process_input(AppState *state, char *input);
void render_app(AppState *app, char *output);
