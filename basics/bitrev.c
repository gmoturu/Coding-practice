#include <stdio.h>
#include <stdlib.h>

int bitrev(int inp)
{
	int i, rev=0, n=inp,j;

	while(n > 0) {
		j++;
		n = n>>1;
	}	
		
	for (i=0; i < j; i++)
	{
		rev = (rev << 1) | (inp & 1);
		inp >>= 1;
		printf("bitrev %d %d \n", rev, inp);
	}
	return rev;
}

int log_2(int n) 
{
	int res; 
	for (res=0; n >= 2; res++) 
		n = n >> 1; 
	return res; 
}

int main()
{
	int i=6, x;
	char buffer [33];
	
	//itoa(i,buffer,2);
	//printf ("binary: %s\n",buffer);
	  
	x = bitrev(i);
	//itoa(x,buffer,2);
	//printf ("binary: %s\n",buffer);
	printf("bitrev %d\n", x);

	return 0;
}
