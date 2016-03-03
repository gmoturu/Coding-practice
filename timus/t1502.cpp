#include<iostream>
using namespace std;
int main()
{
    unsigned long long N;
    std::cin>>N;
    unsigned long long val=(N*(N+1)*(N+2))/2;
    std::cout<<val<<std::endl;
    return 0;
}
