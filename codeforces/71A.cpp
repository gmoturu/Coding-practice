#include<iostream>
#define MAX 10200
using namespace std;
void printWord( char * );
int main()
{
    // get number of words
    short n;
    std::cin>>n;

    // get n number of strings
    char input[MAX];
    for(int i=0,count=0;count<=n&&i<MAX;i++)
    {
	std::cin.get(input[i]);
	if(input[i]=='\n')
	    count++;
    }

    // get each string and print the word
    printWord(input);

    return 0;
}

void printWord( char *input )
{
    char *start=input;
    char *end=input;
    char *next=input;

    for(;*next;next++,end++)
    {
	if(*next=='\n' || !*next)
	{
	    --end;
	    if((end-start)>9)
		std::cout<<*start<<(end-start-1)<<*end;
	    else
		for(char *c=start;c<=end;c++)
		    std::cout<<*c;
		std::cout<<"\n";
	    start=next+1;
	    end=next;
	}
    }
}
