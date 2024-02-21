#pragma once

#include <stdio.h>
#include <string.h>
#include "GameView.h"
#include "../BoardView/BoardView.h"

#define ASCII_TITLE                                   \
  " _______       ______           ______        \n"  \
  "/_  __(_)___  /_  __/__ _____  /_  __/__  ___ \n"  \
  " / / / / __/   / / / _ `/ __/   / / / _ \\/ -_)\n" \
  "/_/ /_/\\__/   /_/  \\_,_/\\__/   /_/  \\___/\\__/ \n\n"

void game_view__initialize(GameView *game_view)
{
  game_view->error = "";
  game_view->message = "";
  board__initialize(&game_view->board);
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, ASCII_TITLE);

  BoardView board_view;
  board_view__initialize(&board_view, &game_view->board);
  board_view__render(&board_view, buffer);

  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->error);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}