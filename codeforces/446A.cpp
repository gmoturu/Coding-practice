#include<iostream>
#include<climits>
using namespace std;

class Weight
{
	public:
		unsigned long seq;
		unsigned long change;
		unsigned long prev;
};

int main()
{
	int N;
	cin>>N;

	unsigned long arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	Weight table[N][N];
	for(int i=0;i<N;i++)
	{
		table[i][i].change=0;
		table[i][i].seq=1;
		table[i][i].prev=arr[i];
	}

	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N-i;j++)
		{
			if(table[j][j+i-1].prev<arr[j+i])
				table[j][j+i].change=table[j][j+i-1].change;
			else
				table[j][j+i].change=table[j][j+i-1].change+1;
			table[j][j+i].prev=table[j][j+i-1].prev+1;
			table[j][j+i].seq=table[j][j+i-1].seq+1;
		}
	}

	unsigned long maxval=0;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(table[i][j].change==1 && maxval<table[i][j].seq)
				maxval=table[i][j].seq;
	cout<<maxval<<endl;

	return 0;
}
