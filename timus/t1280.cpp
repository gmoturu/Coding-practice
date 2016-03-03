#include<iostream>
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
using namespace std;

class Pair
{
	public:
		int x;
		int y;
};

int main()
{
	int N,M;
	cin>>N>>M;

	Pair *pr=new Pair[M];
	for(int i=0;i<M;i++)
		cin>>(pr+i)->x>>(pr+i)->y;

	int *tops=new int[N+1];
	int input;
	for(int i=0;i<N;i++)
	{
		cin>>input;
		tops[input]=i+1;
	}

	int i;
	for(i=0;i<M;i++)
		if(tops[(pr+i)->x]>tops[(pr+i)->y])
			break;

	i==M?YES:NO;

	delete[] pr;
	delete[] tops;

	return 0;
}
