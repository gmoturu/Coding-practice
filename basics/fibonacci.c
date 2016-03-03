// f(0)=0, f(1)=1, f(n)=f(n-1)+f(n-2)
// Given 'n', find f(n) using functions - no need to scanf input
#include<stdio.h>
int main()
{
    int n=10;
    printf( "Fibonacci of n=%d is %d\n",n,fib(n) );
    return 0;
}

int fib( int a )
{
    if ( a==1 )
	return 1;
    else if ( !a )
	return 0;
    else
	return fib(a-1)+fib(a-2);
}
