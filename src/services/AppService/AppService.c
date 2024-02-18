#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AppService.h"
#include "../GameService/GameService.h"
#include "../../config.h"

#include "../../view/BoardView/BoardView.h"
#include "../../view/BoardView/BoardViewMapper/BoardViewMapper.h"
#include "../../view/BoardView/BoardRenderer/BoardRenderer.h"
#include "../InputBuffer/InputBuffer.h"

// TODO: create AppRenderer
#define ASCII_TITLE                                                                           \
  "\n"                                                                                        \
  "d888888b d888888b  .o88b.      d888888b  .d8b.   .o88b.      d888888b  .d88b.  d88888b \n" \
  "`~~88~~'   `88'   d8P  Y8      `~~88~~' d8' `8b d8P  Y8      `~~88~~' .8P  Y8. 88'     \n" \
  "   88       88    8P              88    88ooo88 8P              88    88    88 88ooooo \n" \
  "   88       88    8b              88    88~~~88 8b              88    88    88 88~~~~~ \n" \
  "   88      .88.   Y8b  d8         88    88   88 Y8b  d8         88    `8b  d8' 88.     \n" \
  "   YP    Y888888P  `Y88P'         YP    YP   YP  `Y88P'         YP     `Y88P'  Y88888P \n" \
  "=======================================================================================\n\n"

static void copy_input(char *dst, char *src)
{
  strcpy_s(dst, INPUT_BUFFER_SIZE, src);
}

static void append_output(char *buffer, char *output)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, output);
}

static void quit(AppState *app)
{
  app->is_running = false;
}

static void set_message(AppState *app, char *message)
{
  strcpy_s(app->message, MAX_MESSAGE_SIZE, message);
}

static void new_game(AppState *app)
{
  initialize_game(&app->game);
}

void initialize_app(AppState *app)
{
  new_game(app);
  app->is_running = true;
  input_buffer__initialize(&app->input_buffer, '\n');
  set_message(app, "HELLO WORLD!");
}

bool string_ends_with_new_line(AppState *app, char *input)
{
  size_t length = strlen(input);
  return length >= 2 && input[length - 1] == '\n';
}

void remove_last_character(char *input)
{
  size_t length = strlen(input);
  input[length - 1] = '\0';
}

void process_input(AppState *app, char *input)
{
  InputBuffer_ReadResult result = input_buffer__read(&app->input_buffer, input);

  switch (result)
  {
  case INPUT_BUFFER__READ_RESULT__OVERFLOWING:
    return;

  case INPUT_BUFFER__READ_RESULT__OVERFLOWN:
    set_message(app, "Invalid input");
    return;

  case INPUT_BUFFER__READ_RESULT__OK:
    set_message(app, "TODO!");
    return;
  }

  // char command[INPUT_BUFFER_SIZE];
  // strcpy_s(command, INPUT_BUFFER_SIZE, input);
  // remove_last_character(command);

  // char buffer[128];
  // sprintf_s(buffer, 128, "TODO: process command: %s", command);
  // set_message(app, buffer);

  // if (strcmp(input, "q") == 0)
  // {
  //   quit(app);

  //   return;
  // }
}

static void append_board_view(AppState *app, char *buffer)
{
  BoardView board_view;
  map_game_to_board_view(&app->game, &board_view);

  char *board_view_buffer = create_board_string_buffer();
  render_board_view(&board_view, board_view_buffer);

  append_output(buffer, board_view_buffer);
}

void render_app(AppState *app, char *buffer)
{
  buffer[0] = '\0';

  append_output(buffer, ASCII_TITLE);
  append_board_view(app, buffer);
  append_output(buffer, "\n");
  append_output(buffer, app->message);
  append_output(buffer, "\n");
}
