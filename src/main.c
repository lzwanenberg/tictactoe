#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "services/AppService/AppService.h"
#include "view/BoardView/BoardView.h"
#include "view/BoardView/BoardRenderer/BoardRenderer.h"
#include <stdbool.h>

static void clear_screen();
static void render(AppState *app);
static void request_input(char *buffer);
static void enter_game_loop(AppState *app);

int main()
{
	AppState app;

	clear_screen();
	initialize_app(&app);
	render(&app);
	enter_game_loop(&app);
	clear_screen();

	return 0;
}

void clear_screen()
{
	printf("\033[H\033[J");
}

static void enter_game_loop(AppState *app)
{
	char input[INPUT_BUFFER_SIZE];

	while (app->is_running)
	{
		request_input(input);
		process_input(app, input);
		render(app);
	}
}

static void request_input(char *buffer)
{
	fgets(buffer, sizeof(buffer), stdin);
}

static void render(AppState *app)
{
	char output[OUTPUT_BUFFER_SIZE];
	clear_screen();
	render_app(app, output);
	printf(output);
}
