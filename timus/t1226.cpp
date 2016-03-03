// Assumptions
// There is only 1 space between words
// Non alphabet characters are only at the beginning and end of a word
#include<iostream>
#include<cctype>
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
#define LINE 256
void reverseLine(char *,char *);
void reverseWord(char *,char *);
bool isAlphabet(char *);
using namespace std;
int main()
{
    char line[LINE];
    char *ptr;
    while(cin.getline(line,LINE))
    {
	for(ptr=line;*ptr;ptr++);
	ptr--;
	reverseLine(line,ptr);
	cout<<line<<endl;
    }
    return 0;
}

void reverseLine(char *beg,char *end)
{
    char *first=beg;
    char *last=beg;
    while(*last)
    {
	if(!isspace(*last))
	{
	    last++;
	    continue;
	}
	reverseWord(first,last);
	first=last=last+1;
    }
    if(*first)
	reverseWord(first,last);
}

void reverseWord(char *beg,char *end)
{
    for(end--;beg<end;beg++,end--)
    {
	!isAlphabet(beg)?beg++:beg;
	!isAlphabet(end)?end--:end;
	SWAP(*beg,*end);
    }
}

bool isAlphabet(char *c)
{
    if((*c>='a' && *c<='z')||(*c>='A' && *c<='Z'))
	return 1;
    return 0;
}
