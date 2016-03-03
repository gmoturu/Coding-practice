#include<iostream>
#define STAR std::cout<<"*"
#define LTTR std::cout<<"D"
#define NWLN std::cout<<"\n"
using namespace std;
int main()
{
	int N;
	std::cin>>N;
	int SZ=N/2+1;

	int *arr=new int[SZ];
	arr[0]=1;
	for(int i=1;i<SZ;i++)
		arr[i]=0;

	for(int i=0;i<SZ;i++)
	{
		for(int j=SZ-1;j>0;j--)
			!arr[j]?STAR:LTTR;
		for(int j=0;j<SZ;j++)
			!arr[j]?STAR:LTTR;
		i<SZ-1?arr[i+1]=1:i;
		NWLN;
	}
	arr[SZ-1]=0;
	for(int i=SZ-2;i>=0;i--)
	{
		for(int j=SZ-1;j>0;j--)
			!arr[j]?STAR:LTTR;
		for(int j=0;j<SZ;j++)
			!arr[j]?STAR:LTTR;
		i>0?arr[i]=0:i;
		NWLN;
	}

	delete[] arr;
	return 0;
}
