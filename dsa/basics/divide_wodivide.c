#include<stdio.h>
int dvd(int,int);
int main()
{
  int num,den;
  scanf("%d %d",&num,&den);
  printf("%d\n",dvd(num,den));
  return 0;
}

int dvd(int num,int den)
{
  int count=0;
  while(num>=den)
  {
    num=num-den;
    count++;
  }
  return count;
}
