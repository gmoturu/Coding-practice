#include<iostream>
using namespace std;
int main()
{
	int N;
	int X;

	cin>>N>>X;

	int count=0;
	for(int i=1;i<=N;i++)
		(X%i==0 && X/i<=N)?count++:count;

	cout<<count<<endl;
	return 0;
}
