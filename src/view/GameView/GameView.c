#pragma once

#include <stdio.h>
#include <string.h>
#include "GameView.h"
#include "ascii_art_title.h"
#include "../../config.h"
#include "../BoardView/BoardView.h"

void game_view__render_line(char *buffer, char *content);

void game_view__initialize(GameView *game_view)
{
  game_view__reset(game_view);
  board_view__initialize(&game_view->board_view);
}

void game_view__reset(GameView *game_view)
{
  game_view->error = "";
  game_view->message = "";
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, ASCII_ART_TITLE);
  board_view__render(&game_view->board_view, &game_view->board, buffer);

  game_view__render_line(buffer, game_view->error);
  game_view__render_line(buffer, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, VIEW_MARGIN_LEFT);
}

static void game_view__render_line(char *buffer, char *content)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, VIEW_MARGIN_LEFT);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, content);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}
