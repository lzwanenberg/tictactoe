#include "ByteUtil.h"

/**
 * Creates a byte from an array of boolean values representing individual bits.
 *
 * The function interprets bits[0] as the most significant bit (MSB) and bits[7] as the least significant bit (LSB).
 *
 * @param bits An array of boolean values representing individual bits.
 * @return The byte constructed from the input array of bits.
 */
Byte create_byte(bool bits[8])
{
  Byte result = 0;

  // Iterate over the array in reverse order to interpret bits[0] as the MSB
  for (int i = 7; i >= 0; i--)
  {
    if (bits[i])
    {
      result |= (1 << (7 - i));
    }
  }

  return result;
}
