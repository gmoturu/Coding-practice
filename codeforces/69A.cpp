#include<iostream>
#define YES std::cout<<"YES"<<std::endl
#define NO std::cout<<"NO"<<std::endl
using namespace std;
int main()
{
    int n;
    std::cin>>n;

    int *X,*Y,*Z;
    X = new int[n];
    Y = new int[n];
    Z = new int[n];

    for(int i=0;i<n;i++)
	std::cin>>X[i]>>Y[i]>>Z[i];

    int sum=0;
    for(int i=0;i<n;i++)
	sum+=X[i]+Y[i]+Z[i];

    sum?NO:YES;

    delete X;
    delete Y;
    delete Z;

    return 0;
}
