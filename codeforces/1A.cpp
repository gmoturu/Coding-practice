#include<iostream>
using namespace std;
int main()
{
    uint64_t m,n,a,x,y;
    std::cin>>m>>n>>a;

    m%a?x=m/a+1:x=m/a;
    n%a?y=n/a+1:y=n/a;

    std::cout<<(uint64_t)x*y<<std::endl;
    return 0;
}
