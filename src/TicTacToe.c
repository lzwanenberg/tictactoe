#include <stdio.h>
#include "modulea/Helper.c"
#include "moduleb/Helper.c"

int main()
{
	int result = increment(4);
	int result2 = increment_twice(10);

	printf("Result1: %i\n", result);
	printf("Result2: %i\n", result2);

	return 0;
}
