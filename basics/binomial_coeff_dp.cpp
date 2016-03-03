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
	int MAX=n+1;
	unsigned bin[MAX][MAX];
	for(int i=0;i<MAX;i++)
	{
		bin[i][i]=1;
		bin[i][0]=1;
	}

	for(int i=1;i<MAX;i++)
		for(int j=1;j<i;j++)
			bin[i][j]=bin[i-1][j-1]+bin[i-1][j];

	return bin[n][k];
}
