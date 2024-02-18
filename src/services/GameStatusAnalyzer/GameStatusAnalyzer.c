#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GameStatusAnalyzer.h"
#include "../../config.h"
#include "../../utils/ByteUtil/ByteUtil.h"
#include "../../models/Game/Game.h"
#include "../../models/Move/Move.h"

#define MAX_MOVES_BY_SINGLE_PLAYER MAX_MOVES / 2 + 1

#if BOARD_SIZE != 3
#error "GameStatusAnalyzer assumes a BOARD_SIZE of 3 by 3"
/* A board of 3 x 3 means that we can win in the following ways:
** - 3 rows
** - 3 columns
** - 2 diagonals
** So a total of 8 different ways to make three in a row. Because
** of this perfect number 8, we can perform win condition checks
** using bitwise operation.
*/
#endif

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

typedef char WinConditionProjectionTemplate[3][8][2];
static WinConditionProjectionTemplate PROJECTION_TEMPLATE = {
    {A1, B1, C1, A1, A2, A3, A1, A3},
    {A2, B2, C2, B1, B2, B3, B2, B2},
    {A3, B3, C3, C1, C2, C3, C3, C1}};

typedef struct
{
  int count;
  Move moves[MAX_MOVES_BY_SINGLE_PLAYER];
} MoveSet;

typedef struct
{
  MoveSet player_1;
  MoveSet player_2;
} MoveSets;

typedef Byte Projection[3];

static bool contains_move(MoveSet *move_set, char move[2])
{
  for (int i = 0; i < move_set->count; i++)
  {

    if (move_set->moves[i].col == move[0] &&
        move_set->moves[i].row == move[1])
    {
      return true;
    }
  }

  return false;
}

static Byte create_projection_byte(MoveSet *move_set, char template[8][2])
{
  bool bits[8] = {false};

  for (int i = 0; i < 8; i++)
  {
    bits[i] = contains_move(move_set, template[i]);
  }

  return create_byte(bits);
}

static void create_projection(MoveSet *move_set, Projection projection)
{
  for (int i = 0; i < 3; i++)
  {
    projection[i] = create_projection_byte(move_set, PROJECTION_TEMPLATE[i]);
  }
}

static bool check_for_win(MoveSet *move_set)
{
  Projection projection;
  create_projection(move_set, projection);

  Byte result = projection[0] &
                projection[1] &
                projection[2];

  return result > 0;
}

static void split_moves_per_player(Game *game, char moves_made, MoveSets *moves)
{
  MoveSet *current_player;

  moves->player_1.count = 0;
  moves->player_2.count = 0;

  for (int i = 0; i < moves_made; i++)
  {
    char turn = i / 2;
    current_player = (i % 2 == 0) ? &moves->player_1 : &moves->player_2;
    current_player->moves[turn] = game->moves[i];
    current_player->count++;
  }
}

static char check_for_winner(Game *game, char moves_made)
{
  MoveSets move_sets;
  split_moves_per_player(game, moves_made, &move_sets);

  if (check_for_win(&move_sets.player_1))
    return 1;

  if (check_for_win(&move_sets.player_2))
    return 2;

  return 0;
}

GameStatusAnalyzer_Result game_status_analyzer__analyze(Game *game)
{
  char moves_made = game__count_moves(game);
  char winner = check_for_winner(game, moves_made);

  if (winner == 1)
    return GAME_STATUS_SERVICE__RESULT__P1_WON;

  if (winner == 2)
    return GAME_STATUS_SERVICE__RESULT__P2_WON;

  if (moves_made == MAX_MOVES)
    return GAME_STATUS_SERVICE__RESULT__DRAW;

  return moves_made % 2 == 0
             ? GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1
             : GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2;
}
