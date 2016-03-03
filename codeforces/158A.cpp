#include<iostream>
using namespace std;
int main()
{
    // Get n,k
    unsigned n,k;
    std::cin>>n>>k;

    // create array a and input ranks
    unsigned *a = new unsigned[n];
    for(int i=0;i<n;i++)
	std::cin>>*(a+i);

    // find the number who advanced
    // no need to sort as order is non increasing or sorted
    unsigned i,t;
    for(i=0,t=0;*(a+i)&&i<k;i++,t++);
    for(i=k;*(a+k-1)&&*(a+i)==*(a+k-1)&&i<n;i++,t++);

    std::cout<<t<<std::endl;

    delete a;
    return 0;
}
