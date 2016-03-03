//factorial of a number
#include<stdio.h>
int fact(int);
int fact_loop(int);
int main()
{
  int num;
  scanf("%d",&num);
  printf("%d\n",fact(num));
  return 0;
}

//recursive
int fact(int num)
{
  if(num)
    return num*fact(num-1);
  return 1;
}

//loop
int fact_loop(int num)
{
  int res=1;
  while(num)
    res*=num--;
  return res;
}

