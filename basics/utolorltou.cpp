#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  char name[20];
  cin.getline(name,20);
  char *str=name;

  for(;*str;str++)
  {
    if(*str>='A' && *str<='Z')
      *str+=32;
    else if(*str>='a' && *str<='z')
      *str-=32;
  }

  cout<<name<<endl;
  return 0;
}
