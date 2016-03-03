#include<iostream>
using namespace std;
unsigned binco(unsigned,unsigned);
int main()
{
	unsigned n,k;
	cin>>n>>k;
	cout<<binco(n,k)<<endl;
	return 0;
}

unsigned binco(unsigned n,unsigned k)
{
	if(k==0)
		return 1;
	if(k==1)
		return n;
	if(n==k)
		return 1;
	return binco(n-1,k-1)+binco(n-1,k);
}
