#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "services/AppService/AppService.h"
#include "view/BoardView/BoardView.h"
#include "view/BoardView/BoardRenderer/BoardRenderer.h"
#include <stdbool.h>

int main()
{
	AppState app_state;
	char input[INPUT_BUFFER_SIZE];

	initialize_app(&app_state);

	while (app_state.is_running)
	{
		printf("%s", app_state.output);

		if (fgets(input, sizeof(input), stdin) != NULL)
			process_input(&app_state, input);
		else
			process_invalid_input(&app_state);
	}

	printf("%s", app_state.output);

	return 0;
}
