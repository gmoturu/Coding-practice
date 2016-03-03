#include<iostream>
using namespace std;
int main()
{
  int i=0;
  i|=((1<<4) | (1<<2));
  cout<<i<<endl;
  return 0;
}
