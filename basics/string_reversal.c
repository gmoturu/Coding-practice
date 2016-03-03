#include<stdio.h>
int main()
{
  char p[10];
  scanf("%s",p);
  char *q=p;
  char *s=p;
  while(*q)
    q++;
  for(q--;q>s;q--,s++)
  {
    *s=*s^*q;
    *q=*s^*q;
    *s=*s^*q;
  }
  printf("%s\n",p);
  return 0;
}
