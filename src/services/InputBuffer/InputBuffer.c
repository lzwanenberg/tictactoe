#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "InputBuffer.h"

#define STATE_OK INPUT_BUFFER__STATE__OK
#define STATE_OVERFLOW INPUT_BUFFER__STATE__OVERFLOW

#define READ_OK INPUT_BUFFER__READ_RESULT__OK
#define READ_OVERFLOWING INPUT_BUFFER__READ_RESULT__OVERFLOWING
#define READ_OVERFLOWN INPUT_BUFFER__READ_RESULT__OVERFLOWN

static bool input_is_terminated(InputBuffer *buffer, const char *input)
{
  size_t length = strlen(input);
  if (length == 0)
  {
    return false;
  }

  return input[length - 1] == '\n';
}

void input_buffer__initialize(InputBuffer *input_buffer)
{
  input_buffer->state = STATE_OK;
}

InputBuffer_ReadResult input_buffer__read(InputBuffer *buffer, const char *input)
{
  if (!input_is_terminated(buffer, input))
  {
    buffer->state = STATE_OVERFLOW;
    return READ_OVERFLOWING;
  }

  if (buffer->state == STATE_OVERFLOW)
  {
    buffer->state = STATE_OK;
    return READ_OVERFLOWN;
  }

  return READ_OK;
}
