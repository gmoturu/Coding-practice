#include<iostream>
#define M 20
using namespace std;
int strcmp(const char *str1,const char *str2);
int main()
{
  char str1[M],str2[M];
  cin.getline(str1,M);
  cin.getline(str2,M);
  int val=strcmp(str1,str2);
  cout<<val<<endl;
  return 0;
}

int strcmp(const char *str1,const char *str2)
{
  while(*str1==*str2)
  {
    if(!*str1 && !*str2)
      return 0;
    str1++;
    str2++;
  }
  return (*str1-*str2);
}
