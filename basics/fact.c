#include <stdio.h>

int main ()
{
	int fact=1, n;
	printf("\n enter a number..");
	scanf("%d", &n);

	while(n >= 1)
	{
		fact = fact * n;
		n--;
	}
	printf("\n fact of that number is ...%d\n", fact);
	return fact;
}
