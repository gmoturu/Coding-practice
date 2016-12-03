#include<stdio.h>
_Bool isPower2(int);
int main()
{
  int n;
  scanf("%d",&n);
  isPower2(n)?printf("Power of 2\n"):printf("Not power of 2\n");
  return 0;
}

_Bool isPower2(int n)
{
  if((n&(n-1))==0)
    return 1;
  return 0;
}
