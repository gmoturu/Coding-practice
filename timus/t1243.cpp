#include<iostream>
using namespace std;
int main()
{
    char ch;
    int val=0;
    while((ch=std::cin.get())!='\n')
	val=((val*10)+ch-'0')%7;

    std::cout<<val<<std::endl;
    return 0;
}
