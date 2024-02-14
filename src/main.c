#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "board/Board.h"
#include "view/BoardView.h"
#include "view/BoardRenderer/BoardRenderer.h"

int main()
{
	char *buffer = create_board_string_buffer();

	struct BoardView board_view = {
			.cells = {{CELL_VALUE_X, CELL_VALUE_EMPTY, CELL_VALUE_EMPTY},
								{CELL_VALUE_O, CELL_VALUE_X, CELL_VALUE_O},
								{CELL_VALUE_EMPTY, CELL_VALUE_EMPTY, CELL_VALUE_X}}};

	render_board_view(&board_view, buffer);

	printf("\n\n");
	printf(buffer);
	printf("\n\n");

	free(buffer);

	return 0;
}
