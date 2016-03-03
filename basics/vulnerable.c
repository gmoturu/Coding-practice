#include <stdio.h>
#include <stdlib.h>

unsigned long get_sp(void)
{
	__asm__("movl %esp,%eax");
}

void main(int argc, char *argv[])
{
	char buffer[512];
	int i;
	int *addr;
        long curr_sp = get_sp();
	printf("current sp = %x\n", curr_sp);
	addr = (int *)&buffer;
	printf("addr %x\n", addr);
	printf("diff = %d\n", (curr_sp - (long)addr));
	printf("Start of buffer: 0x%x\n", &buffer);
	printf("End of buffer: 0x%x\n", &buffer[512]);
	if(argc > 1)
		strcpy(buffer, argv[1]);
	//for(i=0; i < 128; i++)
	//printf("addr 0x%x\n", *(addr++));
}

