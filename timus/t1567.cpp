#include<iostream>
#define HSH 100
using namespace std;
int main()
{
    int hash[HSH];
    char chars[32]="abcdefghijklmnopqrstuvwxyz_.,! ";

    int cost=1;
    for(char *ptr=chars;*ptr;ptr++,cost++)
    {
	!(cost%4)?cost=1:cost;
	hash[*ptr-25]=cost%4;
    }

    char ch;
    int sum=0;
    while((ch=std::cin.get())!='\n')
	sum+=hash[ch-25];

    std::cout<<sum<<std::endl;
//    for(char *ptr=chars;*ptr;ptr++)
//	std::cout<<*ptr<<" "<<hash[*ptr-25]<<std::endl;

    return 0;
}
