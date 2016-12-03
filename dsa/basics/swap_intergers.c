//swapping interger related variables
#include<stdio.h>
#define SWAP(a,b) {a^=b;b^=a;a^=b;}
int main()
{
  int a=10,b=20;
  SWAP(a,b);
  printf("%d %d\n",a,b);
  return 0;
}
