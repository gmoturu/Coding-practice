#include<iostream>
using namespace std;
int atoif(const char *);
int main()
{
  char str[10];
  cin>>str;
  cout<<atoif(str)<<endl;
  return 0;
}

int atoif(const char *str)
{
  int temp=0;
  while(*str && (*str>='0' && *str<='9'))
  {
    temp=(temp*10)+(*str-'0');
    str++;
  }
  return temp;
}
