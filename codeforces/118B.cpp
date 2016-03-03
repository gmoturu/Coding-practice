#include<iostream>
using namespace std;
int main()
{
	int N;
	std::cin>>N;

	int *arr=new int[N+1];
	for(int i=0;i<N+1;i++)
		arr[i]=-1;
	arr[0]=0;



	for(int i=0;i<N+1;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<"\n";

	delete[] arr;
	return 0;
}
