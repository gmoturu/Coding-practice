#include<iostream>
using namespace std;
unsigned long long fib( unsigned );
int main()
{
	unsigned n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}

unsigned long long fib( unsigned n )
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	unsigned long long fn2=0,fn1=1,res;
	for(unsigned i=2;i<=n;i++)
	{
		res=fn1+fn2;
		fn2=fn1;
		fn1=res;
	}
	return res;
}
