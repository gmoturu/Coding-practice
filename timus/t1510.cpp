#include<iostream>
using namespace std;
int main()
{
	int N;
	std::cin>>N;

	int *arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	int common=arr[0],counter=0;
	for(int i=0;i<N;i++)
	{
		if(counter==0)
		{
			common=arr[i];
			counter=1;
		}
		else if(arr[i]==common)
			counter++;
		else
			counter--;
	}
	std::cout<<common<<std::endl;
	delete[] arr;

/*  Submitted to timus code below

	int common,counter=0,val;
	for(int i=0;i<N;i++)
	{
		cin>>val;
		if(counter==0)
		{
			common=val;
			counter=1;
		}
		else if(val==common)
			counter++;
		else
			counter--;
	}
	cout<<common<<endl;
*/
	return 0;
}
