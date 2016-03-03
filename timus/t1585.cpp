#include<iostream>
#define EMPEROR std::cout<<"Emperor Penguin"<<std::endl
#define LITTLE std::cout<<"Little Penguin"<<std::endl
#define MACARONI std::cout<<"Macaroni Penguin"<<std::endl
using namespace std;
int main()
{
    int n;
    std::cin>>n;
    std::cin.ignore();

    string inp;
    int emp=0,mac=0,lit=0;
    for(int i=0;i<n;i++)
    {
	getline(cin,inp);
	if(inp.compare("Emperor Penguin")==0)
	    emp++;
	else if(inp.compare("Macaroni Penguin")==0)
	    mac++;
	else if(inp.compare("Little Penguin")==0)
	    lit++;
    }
    emp>mac?emp>lit?EMPEROR:LITTLE:mac>lit?MACARONI:LITTLE;
    return 0;
}

