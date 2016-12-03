#include<stdio.h>
#define MAX 80
#define SWAP(a,b) {a^=b;b^=a;a^=b;}
void reverseString(char *,char *);
void reverseWord(char *);
int main()
{
  char name[MAX];
  gets(name);
  char *q=name;
  while (*q)
    q++;
  reverseString(name,q);
  printf("%s\n",name);
  reverseWord(name);
  printf("%s\n",name);
  return 0;
}

void reverseWord(char *str)
{
  char *end=str;
  while(*end)
    end++;
  char *x=str;
  char *y=str;
  while(x<end)
  {
    x++;
    if(*x==' '||!*x)
    {
      reverseString(y,x);
      y=x+1;
    }
  }
}

void reverseString(char *p,char *q)
{
  for(q--;q>p;q--,p++)
    SWAP(*p,*q);
}
