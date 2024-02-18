#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

#include "MoveInputParser.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void run_test_case(char *input, MoveInputParser_ParseResult expected);
MoveInputParser_ParseResult expect_unsuccessful();
MoveInputParser_ParseResult expect_successful(char col, char row);

void parse_move_input__positive_test_cases(void)
{
  // Row 1
  // A1
  run_test_case("a1", expect_successful(0, 0));
  run_test_case("A1", expect_successful(0, 0));
  run_test_case("1a", expect_successful(0, 0));
  run_test_case("1A", expect_successful(0, 0));
  // B1
  run_test_case("b1", expect_successful(1, 0));
  run_test_case("B1", expect_successful(1, 0));
  run_test_case("1b", expect_successful(1, 0));
  run_test_case("1B", expect_successful(1, 0));
  // C1
  run_test_case("c1", expect_successful(2, 0));
  run_test_case("C1", expect_successful(2, 0));
  run_test_case("1c", expect_successful(2, 0));
  run_test_case("1C", expect_successful(2, 0));

  // Row 2
  // A2
  run_test_case("a2", expect_successful(0, 1));
  run_test_case("A2", expect_successful(0, 1));
  run_test_case("2a", expect_successful(0, 1));
  run_test_case("2A", expect_successful(0, 1));
  // B2
  run_test_case("b2", expect_successful(1, 1));
  run_test_case("B2", expect_successful(1, 1));
  run_test_case("2b", expect_successful(1, 1));
  run_test_case("2B", expect_successful(1, 1));
  // C2
  run_test_case("c2", expect_successful(2, 1));
  run_test_case("C2", expect_successful(2, 1));
  run_test_case("2c", expect_successful(2, 1));
  run_test_case("2C", expect_successful(2, 1));

  // Row 3
  // A2
  run_test_case("a3", expect_successful(0, 2));
  run_test_case("A3", expect_successful(0, 2));
  run_test_case("3a", expect_successful(0, 2));
  run_test_case("3A", expect_successful(0, 2));
  // B2
  run_test_case("b3", expect_successful(1, 2));
  run_test_case("B3", expect_successful(1, 2));
  run_test_case("3b", expect_successful(1, 2));
  run_test_case("3B", expect_successful(1, 2));
  // C2
  run_test_case("c3", expect_successful(2, 2));
  run_test_case("C3", expect_successful(2, 2));
  run_test_case("3c", expect_successful(2, 2));
  run_test_case("3C", expect_successful(2, 2));
}

void parse_move_input__negative_test_cases(void)
{
  MoveInputParser_ParseResult unsuccessful = expect_unsuccessful();

  run_test_case("dd", unsuccessful);
  run_test_case("44", unsuccessful);
  run_test_case("a1b", unsuccessful);
  run_test_case("a1a1", unsuccessful);
  run_test_case("a 1", unsuccessful);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(parse_move_input__positive_test_cases);
  RUN_TEST(parse_move_input__negative_test_cases);
  UNITY_END();

  return 0;
}

static MoveInputParser_ParseResult expect(bool is_successful, char col, char row)
{
  return (MoveInputParser_ParseResult){
      .is_successful = is_successful,
      .col = col,
      .row = row};
}

static MoveInputParser_ParseResult expect_unsuccessful()
{
  return expect(false, -1, -1);
}

static MoveInputParser_ParseResult expect_successful(char col, char row)
{
  return expect(true, col, row);
}

static void run_test_case(char *input, MoveInputParser_ParseResult expected)
{
  MoveInputParser_ParseResult actual;
  move_input_parser__parse(input, &actual);

  char message[128];

  sprintf_s(message, sizeof(message), "is_successful for input '%s'", input);
  TEST_ASSERT_EQUAL_MESSAGE(expected.is_successful, actual.is_successful, message);

  sprintf_s(message, sizeof(message), "col for input '%s'", input);
  TEST_ASSERT_EQUAL_MESSAGE(expected.col, actual.col, message);

  sprintf_s(message, sizeof(message), "row for input '%s'", input);
  TEST_ASSERT_EQUAL_MESSAGE(expected.row, actual.row, message);
}
