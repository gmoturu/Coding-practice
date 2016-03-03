#include<iostream>
#define YES std::cout<<"YES\n"
#define NO std::cout<<"NO\n"
bool lucky(int);
using namespace std;
int main()
{
    int N;
    std::cin>>N;

    int Nprev=N-1;
    int Nnext=N+1;

    (lucky(Nprev)||lucky(Nnext))?YES:NO;
    return 0;
}

bool lucky(int val)
{
    int frst=0;
    int last=0;
    for(int i=0;val && i<3;i++,val=val/10)
	frst+=val%10;
    for(int i=0;val && i<3;i++,val=val/10)
	last+=val%10;
    return frst==last;
}
