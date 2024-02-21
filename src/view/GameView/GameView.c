#pragma once

#include <stdio.h>
#include <string.h>
#include "GameView.h"
#include "ascii_art_title.h"
#include "../BoardView/BoardView.h"

void game_view__render_board(GameView *game_view, char *buffer);

void game_view__initialize(GameView *game_view)
{
  game_view->error = "";
  game_view->message = "";

  board_view__initialize(&game_view->board_view);
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, ASCII_ART_TITLE);
  board_view__render(&game_view->board_view, &game_view->board, buffer);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->error);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}
