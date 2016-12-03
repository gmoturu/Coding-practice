#include <stdio.h>
#include <stdlib.h>

long hextoint(const char* p)
{
	int char_count = 0;
	long x = 0;
	while(*p)
	{
		char c = *p++;
		c -= 48;
		if ((c <0) || (c > 28))  // not a hex character
		{
			x = 0;
			break;
		}
		if(c > 9) c-= 7;
		x <<= 4;
		x += c;
		if(++char_count == 8) break; // thats all we can handle
	}
	return x;
}

int func()
{
	int *a, b;
	*a=0;
	b = *a;
	printf("value is %d, %d\n", *a, b);
	return b;
}

int main()
{
	char *p = {"C2"};
	int c;
	//char *string = "Hello %s", "World!";
	//puts(string);
	char string1[6];
	char string2[] = "Hello!";

	unsigned int *ptr1, *ptr2, *ptr;
	//ptr2 = 0xd00100;
	ptr1 = (int *)malloc(256);
	//ptr = (ptr1 & 0xFFFFFF00) - ptr2;
	//ptr = (ptr1 & 0xFFFFFF00);
	ptr1 = ptr1 << 8;
	//c = func();
	//printf( "Value is %x\n", hextoint(p));
	//printf("value is %d\n", c);
	printf("ptrs: ptr %x ptr1 %x ptr2 %x\n", ptr, ptr1, ptr2);
	return 0;

} 
