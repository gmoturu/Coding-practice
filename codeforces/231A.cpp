#include<iostream>
using namespace std;
int main()
{
    unsigned N;
    std::cin>>N;

    bool *petya = new bool[N];
    bool *vasya = new bool[N];
    bool *tonya = new bool[N];

    for(int i=0;i<N;i++)
	std::cin>>petya[i]>>vasya[i]>>tonya[i];

    int tot=0;
    for(int i=0;i<N;i++)
	petya[i]+vasya[i]+tonya[i]>1?tot++:tot;

    std::cout<<tot<<std::endl;

    delete petya;
    delete vasya;
    delete tonya;

    return 0;
}
