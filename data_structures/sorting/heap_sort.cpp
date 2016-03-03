#include<iostream>
#define N 20
#define LEFT(i) 2*i+1
#define RIGT(i) 2*i+2
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
void heapSortAsc(int *);
void heapSortDes(int *);
void buildMaxHeap(int *);
void buildMinHeap(int *);
void maxHeapify(int *,int,int);
void minHeapify(int *,int,int);
using namespace std;
int main()
{
	int array[N]={10,5,12,2,8,4,6,1,3,9,13,11,7,45,12,3,6,98,56,76};
	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	heapSortAsc(array);

	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	heapSortDes(array);

	for(int i=0;i<N;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";

	return 0;
}

void heapSortAsc(int *arr)
{
	buildMaxHeap(arr);
	for(int i=N-1;i>0;i--)
	{
		SWAP(arr[0],arr[i])
		maxHeapify(arr,0,i);
	}
}

void buildMaxHeap(int *arr)
{
	for(int i=N/2-1;i>=0;i--)
		maxHeapify(arr,i,N);
}

void maxHeapify(int *arr,int i,int n)
{
	int l=LEFT(i);
	int r=RIGT(i);
	int large=i;

	if(l<n && arr[l]>arr[large])
		large=l;
	if(r<n && arr[r]>arr[large])
		large=r;
	if(large!=i)
	{
		SWAP(arr[large],arr[i])
		maxHeapify(arr,large,n);
	}
}

void heapSortDes(int *arr)
{
	buildMinHeap(arr);
	for(int i=N-1;i>0;i--)
	{
		SWAP(arr[0],arr[i])
		minHeapify(arr,0,i);
	}
}

void buildMinHeap(int *arr)
{
	for(int i=N/2-1;i>=0;i--)
		minHeapify(arr,i,N);
}

void minHeapify(int *arr,int i,int n)
{
	int l=LEFT(i);
	int r=RIGT(i);
	int small=i;

	if(l<n && arr[l]<arr[small])
		small=l;
	if(r<n && arr[r]<arr[small])
		small=r;
	if(small!=i)
	{
		SWAP(arr[small],arr[i])
		minHeapify(arr,small,n);
	}
}
