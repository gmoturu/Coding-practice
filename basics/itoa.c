/* itoa example */
#include <stdio.h>
#include <stdlib.h>

void strreverse(char* begin, char* end) {
	char aux;

	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}

void itoa(int value, char* str, int base) {
	static char num[] = "0123456789abcdef";
	char* wstr=str;
	div_t res;

	// Validate base
	if (base<2 || base>35){ *wstr='\0'; return; }

	// Conversion. Number is reversed.
	do {
		res = div(value,base);
		*wstr++ = num[res.rem];
	}while(value=res.quot);

	*wstr='\0';
	printf("%s %s \n", str, wstr);
	// Reverse string
	strreverse(str,wstr-1);
}

int main ()
{
	int i;
	char buffer [33];
	printf ("Enter a number: ");
	scanf ("%d",&i);
	itoa(i,buffer,10);
	printf ("decimal: %s\n",buffer);
	itoa(i,buffer,16);
	printf ("hexadecimal: %s\n",buffer);
	itoa(i,buffer,2);
	printf ("binary: %s\n",buffer);
	return 0;
}
