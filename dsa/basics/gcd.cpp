#include<iostream>
using namespace std;
int gcd(int,int);
int main()
{
  int x,y;
  cin>>x>>y;
  cout<<gcd(x,y)<<endl;
  return 0;
}

int gcd(int x,int y)
{
  int temp;
  while(y>0)
  {
    temp=x%y;
    x=y;
    y=temp;
  }
  return x;
}
