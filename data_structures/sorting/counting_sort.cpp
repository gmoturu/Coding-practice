#include<iostream>
#define N 20
#define K 8
void countingSortAscending(int *);
void countingSortDescending(int *);
using namespace std;
int main()
{
	int array[N]={0,1,4,2,7,1,0,4,2,6,5,1,0,7,3,1,4,5,4,3};
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	countingSortAscending(array);
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	countingSortDescending(array);
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";
	
	return 0;
}

void countingSortAscending(int *array)
{
	int *c_array=new int[K];
	int *sorted=new int[N];

	for(int i=0;i<K;i++)
		c_array[i]=0;
	for(int i=0;i<N;i++)
		c_array[array[i]]++;
	for(int i=1;i<K;i++)
		c_array[i]=c_array[i]+c_array[i-1];
	for(int i=N-1;i>=0;i--)
	{
		sorted[c_array[array[i]]-1]=array[i];
		c_array[array[i]]--;
	}
	for(int i=0;i<N;i++)
		array[i]=sorted[i];

	delete sorted;
	delete c_array;
}

void countingSortDescending(int *array)
{
	int *sorted=new int[N];
	int *c_array=new int[K];

	for(int i=0;i<K;i++)
		c_array[i]=0;
	for(int i=0;i<N;i++)
		c_array[K-1-array[i]]++;
	for(int i=K-2;i>=0;i--)
		c_array[i]=c_array[i]+c_array[i+1];
	for(int i=0;i<N;i++)
	{
		sorted[N-c_array[K-1-array[i]]]=array[i];
		c_array[K-1-array[i]]--;
	}
	for(int i=0;i<N;i++)
		array[i]=sorted[i];

	delete sorted;
	delete c_array;
}
