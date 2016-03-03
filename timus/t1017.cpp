#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;

	unsigned long long stairs[N+1][N+1];
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			stairs[i][j]=0;
	stairs[3][1]=1;
	stairs[4][1]=1;

	for(int i=5;i<=N;i++)
	{
		for(int j=1;j<i-j;j++)
		{
			stairs[i][j]++;
			for(int k=j+1;k<=N;k++)
				if(stairs[i-j][k])
					stairs[i][j]+=stairs[i-j][k];
		}
	}

	unsigned long long count=0;
	for(int i=0;i<=N;i++)
		count+=stairs[N][i];
	cout<<count<<endl;

	return 0;
}
