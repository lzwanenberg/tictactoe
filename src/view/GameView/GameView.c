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
  board__initialize(&game_view->board);
}

void game_view__render(GameView *game_view, char *buffer)
{
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, ASCII_ART_TITLE);
  game_view__render_board(game_view, buffer);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->error);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, game_view->message);
  strcat_s(buffer, OUTPUT_BUFFER_SIZE, "\n");
}

static void game_view__render_board(GameView *game_view, char *buffer)
{
  BoardView board_view;
  board_view__initialize(&board_view, &game_view->board);
  board_view__render(&board_view, buffer);
}