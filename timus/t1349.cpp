#include<iostream>
#define MAX 101
using namespace std;
unsigned long comp(int,int);
int main()
{
    int n;
    std::cin>>n;
    for(int i=1;i<MAX;i++)
	for(int j=i+1;j<MAX;j++)
	    for(int k=j+1;k<MAX;k++)
	    {
		unsigned long ci,cj,ck;
		ci=comp(i,n);	
		cj=comp(j,n);
		ck=comp(k,n);
		if(ci+cj==ck)
		{
		    std::cout<<i<<" "<<j<<" "<<k<<std::endl;
		    return 0;
		}
		else if(ci+cj<ck)
		    break;
	    } 
    std::cout<<"-1\n";
    return 0;
}

unsigned long comp(int num,int pow)
{
    unsigned long ret=1;
    for(int i=1;i<=pow;i++)
	ret*=num;
    return ret;
}
