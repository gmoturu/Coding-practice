#include<iostream>
#include<climits>
using namespace std;
void insertionSort(int *,int);
int main()
{
	int n,m;
	cin>>n>>m;

	int *arr=new int [m];
	for(int i=0;i<m;i++)
		cin>>arr[i];

	insertionSort(arr,m);
	int min=INT_MAX;
	for(int i=0;i+n<=m;i++)
		if(arr[i+n-1]-arr[i]<min)
			min=arr[i+n-1]-arr[i];
	cout<<min<<endl;

	delete [] arr;
	return 0;
}

void insertionSort(int *arr,int m)
{
	for(int i=1;i<m;i++)
	{
		int j,tmp=arr[i];
		for(j=i;j>=1 && tmp<arr[j-1];j--)
			arr[j]=arr[j-1];
		arr[j]=tmp;
	}
}
