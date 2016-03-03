#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;

	int ribbon[n+1];
	for(int i=1;i<=n;i++)
		ribbon[i]=-1;
	ribbon[0]=0;

	for(int sz,i=0;i<3;i++)
	{
		cin>>sz;
		sz<=n?ribbon[sz]=1:ribbon[sz];
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=0;2*j<i+1;j++)
		{
			if(ribbon[j]==-1 || ribbon[i-j]==-1)
				continue;
			ribbon[j]+ribbon[i-j]>ribbon[i]?ribbon[i]=ribbon[j]+ribbon[i-j]:ribbon[i];
		}
	}

	cout<<ribbon[n]<<endl;

	return 0;
}
//			if( parts[j] && parts[i-j] && ribbon[i]<ribbon[j]+ribbon[i-j])
