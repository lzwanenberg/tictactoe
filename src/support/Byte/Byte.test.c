#pragma once
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "Byte.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void to_unsigned_char__0000_0000__is_equal_to_0(void)
{
  bool bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  unsigned char byte = byte__to_unsigned_char(bits);

  TEST_ASSERT_EQUAL(0, byte);
}

void to_unsigned_char__10010011__is_equal_to_147(void)
{
  bool bits[8] = {1, 0, 0, 1, 0, 0, 1, 1};
  unsigned char byte = byte__to_unsigned_char(bits);

  TEST_ASSERT_EQUAL(147, byte);
}

void to_unsigned_char__1111_1111__is_equal_to_255(void)
{
  bool bits[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  unsigned char byte = byte__to_unsigned_char(bits);

  TEST_ASSERT_EQUAL(255, byte);
}

void to_unsigned_char__returned_value__is_compatible_with_bitwise_operations(void)
{
  unsigned char byte1 = byte__to_unsigned_char((bool[8]){1, 1, 0, 1, 1, 0, 1, 1});
  unsigned char byte2 = byte__to_unsigned_char((bool[8]){0, 1, 1, 0, 1, 0, 0, 1});

  unsigned char result = byte1 & byte2;

  unsigned char expected = byte__to_unsigned_char((bool[8]){0, 1, 0, 0, 1, 0, 0, 1});
  TEST_ASSERT_EQUAL(expected, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(to_unsigned_char__0000_0000__is_equal_to_0);
  RUN_TEST(to_unsigned_char__10010011__is_equal_to_147);
  RUN_TEST(to_unsigned_char__1111_1111__is_equal_to_255);
  RUN_TEST(to_unsigned_char__returned_value__is_compatible_with_bitwise_operations);
  UNITY_END();

  return 0;
}
