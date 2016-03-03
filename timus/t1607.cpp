#include<iostream>
#define A std::cout<<a
#define C std::cout<<c
#define NWLN std::cout<<"\n"
using namespace std;
int main()
{
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;

    if(a>c)
	A;
    else
    {
	for(;a<c;a+=b,c-=d);
	a<c+d?A:C+d;
    }
    NWLN;

    return 0;
}
