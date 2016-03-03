#include<iostream>
#define MAX 50
void getAx(char *);
void getRxcy(char *);
void convertToRxcy(char *,char *);
int strToInt(char *,char *);
void printAx(int);
using namespace std;
int main()
{
	int n;
	std::cin>>n;
	std::cin.ignore();

	for(int i=0;i<n;i++)
	{
		char inp[MAX];
		std::cin.getline(inp,MAX);
		char *ptr=inp;
		for(int rxcy=0;*ptr;ptr++)
		{
			if(*ptr>='0' && *ptr<='9')
				rxcy=1;
			if(rxcy==1 && *ptr=='C')
			{
				getAx(inp);
				break;
			}
		}
		if(!*ptr)
			getRxcy(inp);
	}

	return 0;
}

void getAx(char *inp)
{
	char *beg,*end,*lst;
	for(beg=inp;*beg!='C';beg++);
	for(lst=beg;*lst;lst++);
	int val=strToInt(beg+1,lst-1);
	printAx(val);
	for(end=inp+1;*end!='C';end++);
	int num=strToInt(inp+1,end-1);
	std::cout<<num<<std::endl;
}

void getRxcy(char *inp)
{
	char *beg,*end;
	for(beg=inp;*beg>='A';beg++);
	char *lst=beg-1;
	for(end=beg;*end;end++);
	int num=strToInt(beg,end-1);
	std::cout<<"R"<<num<<"C";
	convertToRxcy(inp,lst);
}

void printAx(int num)
{
	char c;
	if(num==0)
		return;
	if(num<26)
	{
		c='A'+num-1;
		std::cout<<c;
		return;
	}
	int val=(num%26);
	val?printAx((num-num%26)/26):printAx(((num-num%26)/26)-1);
	val==0?c='Z':c='A'+val-1;
	std::cout<<c;
}

void convertToRxcy(char *beg,char *end)
{
	int num=0;
	for(;beg<=end;beg++)
	{
		num*=26;
		num+=*beg-'A'+1;
	}
	std::cout<<num<<"\n";
}

int strToInt(char *beg,char *end)
{
	int val=0;
	for(;beg<=end;beg++)
	{
		val*=10;
		val+=*beg-'0';
	}
	return val;
}
