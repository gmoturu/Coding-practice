#include <stdio.h>

main()
{
	int n,i,a;

	printf("enter the number \n");
	scanf("%d",&n);
	if(n==1) {
		printf("it is neither prime nor composite \n");
		return 0;
	} else if (n == 2) {
		printf("the number is prime \n");
		return 0;
	}
	for(i=2;i<n;i++)
	{
		a=n%i;
		if(a==0)
		{
			printf("the number is not a prime number, divisor: %d \n", i);
			return 1;
		}
		else
		{
			continue;
		}
	}
	printf("the number is prime \n");
} 
