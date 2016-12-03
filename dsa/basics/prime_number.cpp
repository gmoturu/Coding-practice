#include<iostream>
using namespace std;
bool isPrime(int);
int main()
{
  int num;
  cin>>num;      
  isPrime(num)?cout<<"Prime"<<endl:cout<<"Composite"<<endl;
  return 0;
}

bool isPrime(int num)
{
  if(num==1 || num==2)
    return true;
  for(int i=2;i*i<=num;i++)
    if(num%i==0)
      return false;
  return true;
}
