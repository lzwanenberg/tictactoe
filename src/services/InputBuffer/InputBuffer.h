#pragma once

#include <stdbool.h>

/**
 * @brief Enumeration representing the state of an InputBuffer.
 */
typedef enum
{
  /**< The input buffer has overflowed. */
  INPUT_BUFFER__STATE__OVERFLOW,

  /**< The input buffer is okay. */
  INPUT_BUFFER__STATE__OK
} InputBuffer_State;

/**
 * @brief Enumeration representing the result of reading input into an InputBuffer.
 */
typedef enum
{
  /**< The read input block is correctly terminated. */
  INPUT_BUFFER__READ_RESULT__OK,

  /**< The read input has not been terminated. */
  INPUT_BUFFER__READ_RESULT__OVERFLOWING,

  /**< The read input has been terminated, but the previous block wasn't. */
  INPUT_BUFFER__READ_RESULT__OVERFLOWN
} InputBuffer_ReadResult;

/**
 * @brief Structure representing an InputBuffer for managing input states.
 */
typedef struct
{
  /**< The state of the InputBuffer. */
  InputBuffer_State state;
} InputBuffer;

/**
 * @brief Initializes an InputBuffer by setting its state to OK.
 *
 * @param input_buffer A pointer to the InputBuffer structure to be initialized.
 */
void input_buffer__initialize(InputBuffer *input_buffer);

/**
 * @brief Reads input into an InputBuffer and returns the read result.
 *
 * @param input_buffer A pointer to the InputBuffer structure.
 * @param input The input string to be read into the buffer.
 * @return The result of reading input as an InputBuffer_ReadResult.
 */
InputBuffer_ReadResult input_buffer__read(InputBuffer *input_buffer, const char *input);
