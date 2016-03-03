//#include<iostream>
//using namespace std;
#include<stdio.h>
int fun(int);
int main()
{
  int num;
  scanf("%d",&num);
//  cout<<fun(num)<<endl;
  printf("%d\n",fun(num));
  return 0;
}

int fun(int num)
{
  int count=0;
  while(num)
  {
    num=num&(num-1);
    count++;
  }
  return count;
}
