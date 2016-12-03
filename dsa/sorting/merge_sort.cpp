#include<iostream>
#define N 20
#define NWLN cout<<"\n"
void mergeSortAscending(int *,int,int);
void sortingAscending(int *,int,int,int);
void mergeSortDescending(int *,int,int);
void sortingDescending(int *,int,int,int);
using namespace std;
int main()
{
	int arr[N]={10,5,12,2,8,4,6,1,3,9,13,11,7,45,12,3,6,98,56,76};

	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	NWLN;

	mergeSortAscending(arr,0,N-1);

	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	NWLN;

	mergeSortDescending(arr,0,N-1);

	for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    NWLN;

	return 0;
}

void mergeSortAscending(int *arr,int beg,int end)
{
	if(beg<end)
	{
		int mid=beg+(end-beg)/2;
		mergeSortAscending(arr,beg,mid);
		mergeSortAscending(arr,mid+1,end);
		sortingAscending(arr,beg,mid,end);
	}
}

void sortingAscending(int *arr,int beg,int mid,int end)
{
	int *A=new int[mid-beg+1];
	int *B=new int[end-mid];

	for(int i=0,k=beg;k<=mid;i++,k++)
		A[i]=arr[k];
	for(int i=0,k=mid+1;k<=end;i++,k++)
		B[i]=arr[k];

	int i=0,j=0,k;
	for(k=beg;i<mid-beg+1 && j<end-mid;k++)
	{
		if(A[i]<B[j])
		{
			arr[k]=A[i];
			i++;
		}
		else
		{
			arr[k]=B[j];
			j++;
		}
	}
	for(;i<mid-beg+1;i++,k++)
		arr[k]=A[i];
	for(;j<end-mid;j++,k++)
		arr[k]=B[j];

	delete[] A;
	delete[] B;
}

void mergeSortDescending(int *arr,int beg,int end)
{
	if(beg<end)
	{
		int mid=beg+(end-beg)/2;
		mergeSortDescending(arr,beg,mid);
		mergeSortDescending(arr,mid+1,end);
		sortingDescending(arr,beg,mid,end);
	}
}

void sortingDescending(int *arr,int beg,int mid,int end)
{
	int *A=new int[mid-beg+1];
	int *B=new int[end-mid];

	for(int k=beg,i=0;k<=mid;i++,k++)
		A[i]=arr[k];
	for(int k=mid+1,i=0;k<=end;i++,k++)
		B[i]=arr[k];

	int i=0,j=0,k;
	for(k=beg;i<mid-beg+1 && j<end-mid;k++)
	{
		if(A[i]>B[j])
		{
			arr[k]=A[i];
			i++;
		}
		else
		{
			arr[k]=B[j];
			j++;
		}
	}
	for(;i<mid-beg+1;i++,k++)
		arr[k]=A[i];
	for(;j<end-mid;j++,k++)
		arr[k]=B[j];

	delete[] A;
	delete[] B;
}
