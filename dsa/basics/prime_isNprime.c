// find if a number is prime
// num is the number - no need to scanf
#include<stdio.h>
int main()
{
    unsigned long num;
    printf( "Enter a number:" );
    scanf( "%lu",&num );
    if ( !(num%2) ) {
	printf( "Not a prime\n" );
	return 0;
    }
    unsigned long max = num/2;
    unsigned long i;
    unsigned long counter=0;
    for ( i=3;i<=max;i=i+2 ) {
	counter++;
	if ( num%i )
	    max = num/i;
	else {
	    printf( "Not a prime\n" );
	    printf( "Total for loop counters is %d\n", counter );
	    return 0;
	}
    }
    printf( "Total for loop counters is %d\n", counter );
    printf( "Prime\n" );
    return 0;
}
