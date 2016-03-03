#include <stdio.h>
#include <stdlib.h>

int ispowerof2(int n)
{
	if ((n & n-1) == 0)
		printf("the given num is power of 2 \n");
	else
		printf("not power of 2 \n");
	return 0;
}
