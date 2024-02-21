#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "services/AppService/AppService.h"
#include "view/BoardView/BoardView.h"
#include <stdbool.h>

void clear_screen();
void render(AppService *app);
void request_input(char *buffer);
void enter_game_loop(AppService *app);

int main()
{
	AppService app;

	app_service__initialize(&app);
	clear_screen();
	render(&app);
	enter_game_loop(&app);
	clear_screen();

	return 0;
}

static void clear_screen()
{
	// TODO
	// printf("\033[H\033[J");
}

static void enter_game_loop(AppService *app)
{
	char input[INPUT_BUFFER_SIZE];

	while (app->is_running)
	{
		request_input(input);
		app_service__process_input(app, input);
		render(app);
	}
}

static void request_input(char *buffer)
{
	fgets(buffer, sizeof(buffer), stdin);
}

static void render(AppService *app)
{
	char output[OUTPUT_BUFFER_SIZE];
	clear_screen();
	app_service__render(app, output);
	printf(output);
}
