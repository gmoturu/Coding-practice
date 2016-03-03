#include<stdio.h>
int main()
{
  int i=1;
  char *p=(char *)&i;
  *p?printf("Little Endian\n"):printf("Big Endian\n");
  return 0;
}
