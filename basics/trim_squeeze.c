//trim or squeeze function
#include<stdio.h>
#define MAX 60
void trimSqueeze(char *,char *);
int main()
{
  char str[MAX];
  gets(str);
  char res[MAX];
  trimSqueeze(str,res);
  printf("%s\n",res);
  return 0;
}
void trimSqueeze(char *str,char *res)
{
  while(*str)
  {
    if(*str==' ')
      str++;
    *res++=*str++;
  }
  *res='\0';
}
