#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AppService.h"
#include "../../config.h"

static void copy_input(char *dst, char *src)
{
  strcpy_s(dst, INPUT_BUFFER_SIZE, src);
}

static void read_input_into_buffer(AppState *app, char *input)
{
  copy_input(app->input_buffer.previous, app->input_buffer.current);
  copy_input(app->input_buffer.current, input);
}

static void write_output(AppState *app, char *output)
{
  strcpy_s(app->output, OUTPUT_BUFFER_SIZE, output);
}

static void clear_output(AppState *app)
{
  write_output(app, "");
}

static void quit(AppState *app)
{
  app->is_running = false;
}

void initialize_app(AppState *app)
{
  app->is_running = true;

  copy_input(app->input_buffer.current, "\n");
  copy_input(app->input_buffer.previous, "\n");
  write_output(app, "Welcome!\n");
}

void process_input(AppState *app, char *input)
{
  clear_output(app);
  read_input_into_buffer(app, input);

  if (strcmp(input, "q\n") == 0)
  {
    write_output(app, "Quitting");
    quit(app);

    return;
  }
}

void process_invalid_input(AppState *app)
{
  printf("TODO: invalid input\n");
}