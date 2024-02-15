#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "GameStatusAnalyzer.h"
#include "../../config.h"
#include "../../utils/GameUtil/GameUtil.h"

GameStatusService_Result analyze_game_status(Game *game)
{
  char moves_made = count_number_of_moves(game);

  // TODO check winner / draw condition

  return moves_made % 2 == 0
             ? GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P1
             : GAME_STATUS_SERVICE__RESULT__WAIT_FOR_MOVE_P2;
}