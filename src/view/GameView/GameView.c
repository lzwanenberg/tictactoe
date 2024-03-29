#pragma once

#include <stdio.h>
#include <string.h>
#include "GameView.h"
#include "ascii_art_title.h"
#include "../BoardView/BoardView.h"

void game_view__render_line(GameView *game_view, char *buffer, char *content);

void game_view__initialize(GameView *game_view, Board *board, char *margin_left)
{
  game_view->board = board;
  game_view->margin_left = margin_left;
  game_view__reset(game_view);
  board_view__initialize(&game_view->board_view, margin_left);
}

void game_view__reset(GameView *game_view)
{
  game_view->error = "";
  game_view->message = "";
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, INDENTED_ASCII_ART_TITLE);
  board_view__render(&game_view->board_view, game_view->board, buffer);

  game_view__render_line(game_view, buffer, game_view->error);
  game_view__render_line(game_view, buffer, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->margin_left);
}

static void game_view__render_line(GameView *game_view, char *buffer, char *content)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->margin_left);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, content);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}
