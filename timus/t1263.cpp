#include<iostream>
using namespace std;
int main()
{
	unsigned N,M,inp;
	std::cin>>N>>M;

	unsigned *votes = new unsigned[N];
	for(int i=0;i<N;i++)
		*(votes+i)=0;

	for(int j=0;j<M;j++)
	{
		std::cin>>inp;
		votes[inp-1]++;
	}

	std::cout.precision(2);
	for(int i=0;i<N;i++)
		std::cout<<std::fixed<<static_cast<float>(100*votes[i])/M<<"%"<<std::endl;

	delete[] votes;
	return 0;
}
