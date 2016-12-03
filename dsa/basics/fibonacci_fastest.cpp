#include<iostream>
using namespace std;
void fib_func(int *,int);
int main()
{
  int n;
  cin>>n;
  int fib_arr[n+1];
  fib_arr[0]=0;
  fib_arr[1]=1;
  fib_func(fib_arr,n);
  for(int i=0;i<=n;i++)
    cout<<fib_arr[i]<<" ";
  cout<<endl;
  return 0;
}

void fib_func(int *fib_arr,int n)
{
  for(int i=2;i<=n;i++)
    fib_arr[i]=fib_arr[i-1]+fib_arr[i-2];
}
