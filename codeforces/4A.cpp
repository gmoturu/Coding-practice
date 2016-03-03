#include<iostream>
#define YES std::cout<<"YES"<<std::endl
#define NO std::cout<<"NO"<<std::endl
using namespace std;
int main()
{
    unsigned short n;
    std::cin>>n;

    n%2?NO:(n>2?YES:NO);

    return 0;
}
