#include<iostream>
using namespace std;
int main()
{
	int T;
	std::cin>>T;
	int *n_arr=new int[T];
	int *k_arr=new int[T];

	for(int i=0;i<T;i++)
		std::cin>>n_arr[i]>>k_arr[i];

	for(int i=0;i<T;i++)
	{
		int sum=0;
		int dist=n_arr[i]/k_arr[i];
		if(n_arr[i]%k_arr[i]==0)
			for(int n=n_arr[i]-dist;n>=dist;n-=dist)
				sum+=dist*n;
		else
		{
			int j,n;
			for(j=0,n=n_arr[i]-dist;j<k_arr[i]-n_arr[i]%k_arr[i] && n>=dist;j++,n-=dist)
				sum+=dist*n;
			for(n-=1;j<k_arr[i]-1;j++,n-=dist+1)
				sum+=n*(dist+1);
		}
		std::cout<<sum<<std::endl;
	}

	delete[] n_arr;
	delete[] k_arr;

	return 0;
}
