#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../../config.h"

// #define EMPTY_MOVE_CODE -1
// #define MOVE_OUT_OF_BOUNDS_CODE -2

// static void reset_moves(Game *game);
// static int get_move_id(Move *move);
// static bool game_has_finished(GameState state);

// void initialize_game(Game *game)
// {
//   reset_moves(game);
// }

// static void reset_moves(Game *game)
// {
//   for (int i = 0; i < MAX_MOVES; i++)
//     game->moves[i] = EMPTY_MOVE_CODE;
// }

// static int get_move_id(Move *move)
// {
//   if (move->col >= BOARD_SIZE || move->row >= BOARD_SIZE)
//     return MOVE_OUT_OF_BOUNDS_CODE;

//   return move->col + (move->row * BOARD_SIZE);
// }

// static bool game_has_finished(GameState state)
// {
//   return state == GAME_STATE__P1_WON ||
//          state == GAME_STATE__P2_WON ||
//          state == GAME_STATE__DRAW;
// }

// static bool is_cell_free(Game *game, int move_id)
// {
//   for (int i = 0; i < MAX_MOVES; i++)
//   {
//     if (game->moves[i] == EMPTY_MOVE_CODE)
//       return true;

//     if (game->moves[i] == move_id)
//       return false;
//   }

//   return true;
// }

// static Game_MoveValidity validate_move(Game *game, GameState state, int move_id)
// {
//   if (game_has_finished(state))
//     return GAME__MOVE_VALIDITY__INVALID_FINISHED;

//   if (move_id == MOVE_OUT_OF_BOUNDS_CODE)
//     return GAME__MOVE_VALIDITY__INVALID_OUT_OF_BOUNDS;

//   if (!is_cell_free(game, move_id))
//     return GAME__MOVE_VALIDITY__INVALID_CELL_OCCUPIED;

//   return GAME__MOVE_VALIDITY__VALID;
// }

// static int find_first_empty_move_index(Game *game)
// {
//   for (int i = 0; i < MAX_MOVES; i++)
//   {
//     if (game->moves[i] == EMPTY_MOVE_CODE)
//       return i;
//   }
//   return -1;
// }

// static void set_next_move(Game *game, int move_id)
// {
//   int i = find_first_empty_move_index(game);
//   game->moves[i] = move_id;
// }

// Game_MoveResult attempt_make_move(Game *game, Move *move)
// {
//   int move_id = get_move_id(move);
//   GameState state = calculate_game_state(game);
//   Game_MoveValidity move_validity = validate_move(game, state, move_id);

//   if (move_validity != GAME__MOVE_VALIDITY__VALID)

//     return (Game_MoveResult){
//         .move_validity = move_validity,
//         .state = state};

//   set_next_move(game, move_id);
//   GameState new_state = calculate_game_state(game);

//   return (Game_MoveResult){
//       .move_validity = move_validity,
//       .state = new_state};
// }
