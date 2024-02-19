#pragma once
#include "../../src/models/Game/Game.h"

#define CREATE_GAME(arr) create_non_empty(arr, sizeof(arr) / sizeof(arr[0]))

#define CELL(col, row) \
  {                    \
    col, row           \
  }

#define A1 CELL(0, 0)
#define A2 CELL(0, 1)
#define A3 CELL(0, 2)
#define B1 CELL(1, 0)
#define B2 CELL(1, 1)
#define B3 CELL(1, 2)
#define C1 CELL(2, 0)
#define C2 CELL(2, 1)
#define C3 CELL(2, 2)

static char ONGOING_TURN_P1[][2] = {B2, A3, B3, B1};
static char ONGOING_TURN_P2[][2] = {B2, A3, B3, B1, A1};
static char DRAW[][2] = {B2, A3, B3, B1, A1, C3, A2, C2, C1};
static char P1_WON[][2] = {A1, A2, B1, B2, C1};
static char P2_WON[][2] = {C3, A1, A2, B1, B2, C1};

static Game
create_empty()
{
  Game game;
  game__initialize(&game);
  return game;
}

static Game create_non_empty(char moves[][2], int size)
{
  Game game;
  game__load(&game, moves, size);
  return game;
}

Game game_stub__empty()
{
  return create_empty();
}

Game game_stub__draw()
{
  return CREATE_GAME(DRAW);
}

Game game_stub__ongoing()
{
  return CREATE_GAME(ONGOING_TURN_P1);
}

Game game_stub__ongoing_turn_p1()
{
  return CREATE_GAME(ONGOING_TURN_P1);
}

Game game_stub__ongoing_turn_p2()
{
  return CREATE_GAME(ONGOING_TURN_P2);
}

Game game_stub__p1_won()
{
  return CREATE_GAME(P1_WON);
}

Game game_stub__p2_won()
{
  return CREATE_GAME(P2_WON);
}
