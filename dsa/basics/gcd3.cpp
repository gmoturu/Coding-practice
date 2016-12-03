#include<iostream>
using namespace std;
int gcd(int,int,int);
int main()
{
  int x,y,z;
  cin>>x>>y>>z;
  cout<<gcd(x,y,z)<<endl;
  return 0;
}

int gcd(int x,int y,int z)
{
  int count=0;
  while(z>0)
  {
    count++;
    int temp=x%y;
    x=y;
    if(temp>z)
    {
      y=temp;
    }
    else
    {
      y=z;
      z=temp;
    }
  }
  cout<<count<<endl;
  return y;
}
