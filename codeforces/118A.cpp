#include<iostream>
#define MAX 101
using namespace std;
int main()
{
    char input[MAX];
    char output[2*MAX];
    std::cin>>input;

    char *inp=input;
    char *out=output;

    for(;*inp;inp++)
    {
	int vowel=0;
	switch (*inp)
	{
	    case 'A':
	    case 'a':
	    case 'E':
	    case 'e':
	    case 'I':
	    case 'i':
	    case 'O':
	    case 'o':
	    case 'U':
	    case 'u':
	    case 'Y':
	    case 'y':
		vowel=1;
	}
	if(!vowel)
	{
	    *out='.';
	    out++;
	    (*inp<97)?*out=*inp+32:*out=*inp;
	    out++;
	}
    }
    *out='\0';

    std::cout<<output<<std::endl;

    return 0;
}	
