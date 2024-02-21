#pragma once
#include <stdbool.h>

/**
 * @brief Converts an array of boolean bits to an unsigned char byte.
 *
 * This function takes an array of 8 boolean bits and converts them to
 * an unsigned char byte. The most significant bit (MSB) of the byte
 * corresponds to `bits[0]`, and the least significant bit LMSB) corresponds
 * to `bits[7]`.
 *
 * @param bits An array of 8 boolean bits representing a byte.
 * @return The unsigned char byte value generated from the boolean bits.
 */
unsigned char byte__to_unsigned_char(bool bits[8]);
