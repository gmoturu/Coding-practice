#include<stdio.h>
_Bool palin(char *);
int main()
{
  char str[20];
  scanf("%s",str);
  palin(str)?printf("Palindrome\n"):printf("Not Palindrome\n");
  return 0;
}
  
_Bool palin(char *str)
{
  char *end=str;
  while(*end)
    end++;
  for(end--;end>str;end--,str++)
    if(*end!=*str)
      return 0;
  return 1;
}
