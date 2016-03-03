#include<iostream>
#define N 20
void insertionSortAscending(int *);
void insertionSortDescending(int *);
using namespace std;
int main()
{
	int array[N]={10,5,12,2,8,4,6,1,3,9,13,11,7,45,12,3,6,98,56,76};
	for(int i=0;i<N;i++)
		std::cout<<array[i]<<" ";
	std::cout<<"\n";

	insertionSortAscending(array);
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	insertionSortDescending(array);
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	return 0;
}

void insertionSortAscending(int *array)
{
	for(int i=1;i<N;i++)
	{
		int j,tmp=array[i];
		for(j=i-1;array[j]>tmp && j>=0;j--)
			array[j+1]=array[j];
		array[j+1]=tmp;
	}
}

void insertionSortDescending(int *array)
{
	for(int i=1;i<N;i++)
	{
		int j,tmp=array[i];
		for(j=i-1;array[j]<tmp && j>=0;j--)
			array[j+1]=array[j];
		array[j+1]=tmp;
	}
}
