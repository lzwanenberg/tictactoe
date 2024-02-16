#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "view/BoardView/BoardView.h"
#include "view/BoardView/BoardRenderer/BoardRenderer.h"
#include <stdbool.h>

#define _ BOARD_VIEW__CELL_EMPTY
#define X BOARD_VIEW__CELL_P1
#define O BOARD_VIEW__CELL_P2

#define MAX_INPUT_LENGTH 8
#define NEW_LINE "$" // Custom string to replace '\n'

static bool check_string_ends_with_newline(char *str)
{
	size_t length = strlen(str);
	return length > 0 && str[length - 1] == '\n';
}

int main()
{
	bool quit = false;
	char previous_input[MAX_INPUT_LENGTH] = "\n";
	char input[MAX_INPUT_LENGTH] = "\n";

	do
	{
		// Read input until the user presses Enter
		if (fgets(input, sizeof(input), stdin) != NULL)
		{
			bool previous_ends_with_new_line = check_string_ends_with_newline(previous_input);
			bool new_ends_with_new_line = check_string_ends_with_newline(input);
			bool should_process = previous_ends_with_new_line && new_ends_with_new_line;

			if (!should_process && new_ends_with_new_line)
			{
				printf("Invalid command.\n");
			}
			else if (should_process)
			{
				printf("TODO: check for command.\n");
			}
		}
		else
		{
			printf("Error reading input.\n");
		}

		strcpy_s(previous_input, MAX_INPUT_LENGTH, input);
	} while (!quit);

	return 0;
}

// int main()
// {
// create game

// create loop:
// show feedback
// receive command
// process command

// char *buffer = create_board_string_buffer();

// BoardView board_view = {
// 		.cells = {{X, _, _},
// 							{O, X, O},
// 							{_, _, X}}};

// render_board_view(&board_view, buffer);

// printf("\n\n");
// printf(buffer);
// printf("\n\n");

// free(buffer);

// return 0;
// }
