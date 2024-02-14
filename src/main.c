﻿#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "board/Board.h"
#include "view/BoardView/BoardView.h"
#include "view/BoardView/BoardRenderer/BoardRenderer.h"

#define _ BOARD_VIEW__CELL_EMPTY
#define X BOARD_VIEW__CELL_X
#define O BOARD_VIEW__CELL_O

int main()
{
	char *buffer = create_board_string_buffer();

	struct BoardView board_view = {
			.cells = {{X, _, _},
								{O, X, O},
								{_, _, X}}};

	render_board_view(&board_view, buffer);

	printf("\n\n");
	printf(buffer);
	printf("\n\n");

	free(buffer);

	return 0;
}
