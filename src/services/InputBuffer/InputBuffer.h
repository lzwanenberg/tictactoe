#pragma once

#include <stdbool.h>

typedef enum
{
  INPUT_BUFFER__STATE__OVERFLOW,
  INPUT_BUFFER__STATE__OK,
} InputBuffer_State;

typedef enum
{
  /** Read input block is correctly terminated */
  INPUT_BUFFER__READ_RESULT__OK,

  /** Read input has not been terminated */
  INPUT_BUFFER__READ_RESULT__OVERFLOWING,

  /** Read input has been terminated, but the previous block wasn't */
  INPUT_BUFFER__READ_RESULT__OVERFLOWN,
} InputBuffer_ReadResult;

typedef struct
{
  char terminator;
  InputBuffer_State state;
} InputBuffer;

void input_buffer__initialize(InputBuffer *input_buffer, char terminator);

InputBuffer_ReadResult input_buffer__read(InputBuffer *input_buffer, const char *input);
