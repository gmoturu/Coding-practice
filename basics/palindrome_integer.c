// find if an integer is palindrome
#include<stdio.h>
int main()
{
    printf( "Enter an integer:" );
    int num;
    scanf( "%d", &num );
    int temp=num;
    int palin=0;
    while( temp ) {
	palin*=10;
	palin+=temp%10;
	temp/=10;
    }
    num==palin?printf( "Palindrome\n" ):printf( "Not a palindrome\n" );
    return 0;
}
