#include<stdio.h>
void sumDigits(int);
int main()
{
  int num,sum=0;
  scanf("%d",&num);
  for(;num;sum+=num%10,num/=10);
  printf("%d\n",sum);
  return 0;
}
