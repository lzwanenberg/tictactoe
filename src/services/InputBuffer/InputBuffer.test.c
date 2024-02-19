#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

#include "InputBuffer.h"

#define OK INPUT_BUFFER__READ_RESULT__OK
#define OVERFLOWING INPUT_BUFFER__READ_RESULT__OVERFLOWING
#define OVERFLOWN INPUT_BUFFER__READ_RESULT__OVERFLOWN

void setUp(void)
{
}

void tearDown(void)
{
}

void read__valid_blocks__returns_ok(void)
{
  InputBuffer buffer;
  input_buffer__initialize(&buffer);

  char *block1 = "First terminated block\n";
  char *block2 = "Second terminated block\n";

  InputBuffer_ReadResult result1 = input_buffer__read(&buffer, block1);
  InputBuffer_ReadResult result2 = input_buffer__read(&buffer, block2);

  TEST_ASSERT_EQUAL(OK, result1);
  TEST_ASSERT_EQUAL(OK, result2);
}
void read__unterminated_block__returns_overflowing(void)
{
  InputBuffer buffer;
  input_buffer__initialize(&buffer);

  char *block1 = "Unterminated block";

  InputBuffer_ReadResult result = input_buffer__read(&buffer, block1);

  TEST_ASSERT_EQUAL(OVERFLOWING, result);
}

void read__terminated_block_after_unterminated_block__returns_overflown(void)
{
  InputBuffer buffer;
  input_buffer__initialize(&buffer);

  char *block1 = "Unterminated block";
  char *block2 = "Unterminated block";
  char *block3 = "Terminated block\n";

  InputBuffer_ReadResult result1 = input_buffer__read(&buffer, block1);
  InputBuffer_ReadResult result2 = input_buffer__read(&buffer, block2);
  InputBuffer_ReadResult result3 = input_buffer__read(&buffer, block3);

  TEST_ASSERT_EQUAL(OVERFLOWING, result1);
  TEST_ASSERT_EQUAL(OVERFLOWING, result2);
  TEST_ASSERT_EQUAL(OVERFLOWN, result3);
}

void read__terminated_block_after_overflown__returns_ok(void)
{
  InputBuffer buffer;
  input_buffer__initialize(&buffer);

  char *block1 = "Unterminated block";
  char *block2 = "First terminated block\n";
  char *block3 = "Second terminated block\n";

  InputBuffer_ReadResult result1 = input_buffer__read(&buffer, block1);
  InputBuffer_ReadResult result2 = input_buffer__read(&buffer, block2);
  InputBuffer_ReadResult result3 = input_buffer__read(&buffer, block3);

  TEST_ASSERT_EQUAL(OVERFLOWING, result1);
  TEST_ASSERT_EQUAL(OVERFLOWN, result2);
  TEST_ASSERT_EQUAL(OK, result3);
}

void read__empty_block__returns_overflowing(void)
{
  InputBuffer buffer;
  input_buffer__initialize(&buffer);

  char *block1 = "";

  InputBuffer_ReadResult result1 = input_buffer__read(&buffer, block1);

  TEST_ASSERT_EQUAL(OVERFLOWING, result1);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(read__valid_blocks__returns_ok);
  RUN_TEST(read__unterminated_block__returns_overflowing);
  RUN_TEST(read__terminated_block_after_unterminated_block__returns_overflown);
  RUN_TEST(read__terminated_block_after_overflown__returns_ok);
  RUN_TEST(read__empty_block__returns_overflowing);
  UNITY_END();

  return 0;
}
