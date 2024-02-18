#include "Byte.h"

unsigned char byte__to_unsigned_char(bool bits[8])
{
  unsigned char result = 0;

  for (int i = 7; i >= 0; i--)
  {
    if (bits[i])
    {
      result |= (1 << (7 - i));
    }
  }

  return result;
}
