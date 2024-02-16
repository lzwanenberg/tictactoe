#pragma once
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "ByteUtil.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void create_byte__0000_0000__is_equal_to_0(void)
{
  bool bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  Byte byte = create_byte(bits);

  TEST_ASSERT_EQUAL(0, byte);
}

void create_byte__10010011__is_equal_to_147(void)
{
  bool bits[8] = {1, 0, 0, 1, 0, 0, 1, 1};
  Byte byte = create_byte(bits);

  TEST_ASSERT_EQUAL(147, byte);
}

void create_byte__1111_1111__is_equal_to_255(void)
{
  bool bits[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  Byte byte = create_byte(bits);

  TEST_ASSERT_EQUAL(255, byte);
}

void create_byte__returned_value__is_compatible_with_bitwise_operations(void)
{
  Byte byte1 = create_byte((bool[8]){1, 1, 0, 1, 1, 0, 1, 1});
  Byte byte2 = create_byte((bool[8]){0, 1, 1, 0, 1, 0, 0, 1});

  Byte result = byte1 & byte2;

  Byte expected = create_byte((bool[8]){0, 1, 0, 0, 1, 0, 0, 1});
  TEST_ASSERT_EQUAL(expected, result);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(create_byte__0000_0000__is_equal_to_0);
  RUN_TEST(create_byte__10010011__is_equal_to_147);
  RUN_TEST(create_byte__1111_1111__is_equal_to_255);
  RUN_TEST(create_byte__returned_value__is_compatible_with_bitwise_operations);
  UNITY_END();

  return 0;
}
