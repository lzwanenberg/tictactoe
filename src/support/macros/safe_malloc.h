#pragma once

/**
 * @brief Safely allocate memory.
 *
 * This macro is used to safely allocate memory using malloc. It checks if
 * memory allocation succeeds and terminates the program with an error message
 * if allocation fails.
 *
 * @param ptr Pointer variable to store the allocated memory address.
 * @param size Size of the memory block to allocate.
 */
#define SAFE_MALLOC(ptr, size)                       \
  do                                                 \
  {                                                  \
    ptr = malloc(size);                              \
    if (ptr == NULL)                                 \
    {                                                \
      fprintf(stderr, "Memory allocation failed\n"); \
      exit(EXIT_FAILURE);                            \
    }                                                \
  } while (0)
