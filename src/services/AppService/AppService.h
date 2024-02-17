#pragma once

#include <stdbool.h>
#include "../../config.h"
#include "../../types/Game.h"

typedef struct
{
  char previous[INPUT_BUFFER_SIZE];
  char current[INPUT_BUFFER_SIZE];
} InputBuffer;

typedef struct
{
  InputBuffer input_buffer;
  bool is_running;
  char output[OUTPUT_BUFFER_SIZE];
  Game game;
} AppState;

void initialize_app(AppState *state);
void process_input(AppState *state, char *input);
void process_invalid_input(AppState *state);
