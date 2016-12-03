#include<iostream>
using namespace std;
void strcpy(char *,const char *);
int main()
{
  char str[20];
  char nstr[20];
  cin.getline(str,20);
  strcpy(nstr,str);
  cout<<nstr<<endl;
  return 0;
}

void strcpy(char *nstr,const char *str)
{
  while(*str)
    *nstr++=*str++;
  *nstr='\0';
}
