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

static void read_input_into_buffer(AppState *app, char *input)
{
  copy_input(app->input_buffer.previous, app->input_buffer.current);
  copy_input(app->input_buffer.current, input);
}

static void append_output(char *buffer, char *output)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, output);
}

static void quit(AppState *app)
{
  app->is_running = false;
}

static void initialize_input_buffer(AppState *app)
{
  copy_input(app->input_buffer.current, "\n");
  copy_input(app->input_buffer.previous, "\n");
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
  set_message(app, "HELLO WORLD!");
  initialize_input_buffer(app);
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
  read_input_into_buffer(app, input);
  if (!string_ends_with_new_line(app, app->input_buffer.current))
  {
    // Buffer overflowing, wait until new line character enters buffer
    return;
  }
  if (!string_ends_with_new_line(app, app->input_buffer.previous))
  {
    // Buffer overflow
    set_message(app, "Invalid input.");
    return;
  }

  char command[INPUT_BUFFER_SIZE];
  strcpy_s(command, INPUT_BUFFER_SIZE, input);
  remove_last_character(command);

  char buffer[128];
  sprintf_s(buffer, 128, "TODO: process command: %s", command);
  set_message(app, buffer);

  // TODO, define module that parses commands
  if (strcmp(input, "q") == 0)
  {
    quit(app);

    return;
  }
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
