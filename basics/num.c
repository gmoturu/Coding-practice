#include <stdio.h>

void print(int *b)
{
	printf("array %d %d \n", *(b + 50), b[50]);
	return;
}

main(){

	int i=-1, j=1, k, l, a[100];
	k=i&&j;
	l=i||j;
	a[50] = 10;
	print(a);
	printf("l = %d, j = %d \n", l, j);
}
