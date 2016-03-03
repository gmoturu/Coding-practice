#include<iostream>
using namespace std;
int main()
{
    int N;
    std::cin>>N;

    int *arr=new int[N];
    for(int i=0;i<N;i++)
	std::cin>>arr[i];

    int count=0,prev=arr[0];
    for(int i=0;i<N;i++)
    {
	if(arr[i]==prev)
	    count++;
	else
	{
	    std::cout<<count<<" "<<prev<<" ";
	    count=1;
	    prev=arr[i];
	}
    }
    std::cout<<count<<" "<<prev<<" "<<std::endl;

    delete[] arr;
    return 0;
}
