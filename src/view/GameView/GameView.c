#pragma once

#include <stdio.h>
#include <string.h>
#include "GameView.h"

#define ASCII_TITLE                                                                           \
  "\n"                                                                                        \
  "d888888b d888888b  .o88b.      d888888b  .d8b.   .o88b.      d888888b  .d88b.  d88888b \n" \
  "`~~88~~'   `88'   d8P  Y8      `~~88~~' d8' `8b d8P  Y8      `~~88~~' .8P  Y8. 88'     \n" \
  "   88       88    8P              88    88ooo88 8P              88    88    88 88ooooo \n" \
  "   88       88    8b              88    88~~~88 8b              88    88    88 88~~~~~ \n" \
  "   88      .88.   Y8b  d8         88    88   88 Y8b  d8         88    `8b  d8' 88.     \n" \
  "   YP    Y888888P  `Y88P'         YP    YP   YP  `Y88P'         YP     `Y88P'  Y88888P \n" \
  "=======================================================================================\n\n"

void game_view__initialize(GameView *game_view)
{
  game_view->input_error = "";
  game_view->message = "";
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, ASCII_TITLE);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->input_error);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}