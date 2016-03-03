#include<iostream>
using namespace std;
int main()
{
    int tx,ty;
    std::cin>>tx>>ty;

    int bx,by,ign;
    std::cin>>ign>>by>>bx;
    std::cin>>ign;

    std::cout<<tx-bx<<" "<<ty-by<<std::endl;
    return 0;
}
