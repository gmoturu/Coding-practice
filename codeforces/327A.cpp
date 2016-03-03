#include<iostream>
#include<climits>
#define NWLN cout<<"\n"
using namespace std;
int main()
{
	int N;
	cin>>N;
	bool arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	int count=0;
	for(int i=0;i<N;i++)
		arr[i]?count++:count;

	int tmp,tested,max=INT_MIN;

	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tmp=count;
			tested=0;
			for(int k=j;k<j+i && j+i<=N;k++)
			{
				arr[k]?tmp--:tmp++;
				tested=1;
			}
			tested && max<tmp?max=tmp:max;
		}
	}

	cout<<max<<endl;

	return 0;
}
