
#pragma once

#include "../modulea/Helper.c"

int increment_twice(int value)
{
  return increment(increment(value));
}