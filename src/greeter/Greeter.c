#include "Greeter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *greet(const char *name)
{
  const char *greeting = malloc(strlen(name) + 8); // "Hello, " + null terminator
  if (greeting == NULL)
  {
    return NULL; // Memory allocation failed
  }
  sprintf(greeting, "Hello, %s!", name);
  return greeting;
}
