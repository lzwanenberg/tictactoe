#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "board/Board.c"
#include "view/BoardView.c"

int main()
{
	char *buffer = create_board_string_buffer();

	struct TicTacToeBoard board2 = {
			.cells = {{CELL_VALUE_X, CELL_VALUE_EMPTY, CELL_VALUE_EMPTY},
								{CELL_VALUE_O, CELL_VALUE_X, CELL_VALUE_O},
								{CELL_VALUE_EMPTY, CELL_VALUE_EMPTY, CELL_VALUE_X}}};

	board_to_string(&board2, buffer);

	printf("\n\n");
	printf(buffer);
	printf("\n\n");

	free(buffer);

	return 0;
}
