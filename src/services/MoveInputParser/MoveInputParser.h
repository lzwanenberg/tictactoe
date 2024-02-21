#pragma once

#include <stdbool.h>
#include "../../models/Move/Move.h"

/**
 * @brief Represents the result of parsing move input.
 */
typedef struct
{
  /**< Indicates whether the parsing was successful. */
  bool is_successful;

  /**< Move representing the parsed move*/
  Move move;
} MoveInputParser_ParseResult;

/**
 * @brief Parses move input to extract column and row information.
 *
 * @param input The input string containing move information.
 * @param result A pointer to the MoveInputParser_ParseResult structure to store the parsing result.
 */
void move_input_parser__parse(const char *input, MoveInputParser_ParseResult *result);
