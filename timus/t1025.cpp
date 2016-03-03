#include<iostream>
using namespace std;
void insertionSort(int *,int);
int main()
{
    int K;
    cin>>K;

    int *arr=new int[K];
    for(int i=0;i<K;i++)
	cin>>arr[i];
    insertionSort(arr,K);

    int sum=0;
    for(int i=0;i<K/2+1;i++)
	sum+=arr[i]/2+1;
    cout<<sum<<endl;

    delete[] arr;
    return 0;
}

void insertionSort(int *arr,int K)
{
    for(int i=1,j,val;i<K;i++)
    {
	for(j=i-1,val=arr[i];arr[j]>val && j>-1;j--)
	    arr[j+1]=arr[j];
	arr[j+1]=val;
    }
}
