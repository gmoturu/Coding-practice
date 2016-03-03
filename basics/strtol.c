/* strtol example */
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[])
{
	char szNumbers[] = "10100000";
	char addr[10];
	char * pEnd;
	
	strcpy(addr, argv[1]);
	int li1, li2, li3, li4, li5;
	li1 = strtol (szNumbers,NULL,10);
	li2 = strtol (szNumbers,NULL,16);
	li3 = strtol (szNumbers,NULL,2);
	li5 = strtol (argv[1],NULL,16);
	printf ("The decimal equivalents are: %ld, %ld, %ld %ld.\n", li1, li2, li3, li4);
	printf ("addr is: %ld, %ld\n", li5, (uint )li5);
	return 0;
}
