#include <stdio.h>
#include <stdlib.h>

//memalign posix_memalign

char * malloc_align(int data, int offset)
{
	char *buffer;

	buffer = (char *)malloc(sizeof(int));
	printf("startng address....%p\n", buffer);
	printf("startng address....%d\n", buffer);

	return buffer;
}


int main ()
{
	int data=1000, offset=1024;
	char *buffer;
	
	buffer = (char *)malloc_align(data, offset);
	free(buffer);
	return 1;
}
