#include<iostream>
unsigned long long factorial(int);
unsigned long long bincoeff(int,int);
using namespace std;
int main()
{
	int k;
	cin>>k;
	int N=-2,K=k;
	int val;
	for(int i=0;i<k;i++)
	{
		cin>>val;
		N+=val;
		val==1?((i==k-2 || i==k-1)?K--:K):K;
	}

	cout<<N<<" "<<K<<endl;
	cout<<bincoeff(N,K)*factorial(N-K)<<endl;
	return 0;
}

unsigned long long factorial(int num)
{
	if(num==1)
		return 1;
	return num*factorial(num-1);
}

unsigned long long bincoeff(int N,int K)
{
	unsigned long long arr[N+1][N+1];
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			arr[i][j]=0;
	for(int i=0;i<=N;i++)
		arr[i][0]=1;
	for(int i=0;i<=N;i++)
		arr[i][i]=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<i;j++)
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
	return arr[N][K];
}
