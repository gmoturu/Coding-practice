#include<iostream>
#define MAX 100
int isPresent(int *,int);
void isMirror(int *);
void printMirror(int,int,int *);
using namespace std;
int main()
{
    int arr[MAX];
    isMirror(arr);

    int n;
    std::cin>>n;

    int index=isPresent(arr,n);
    if(index==-1)
	std::cout<<"Glupenky Pierre"<<std::endl;
    else
	printMirror(index,n,arr);
    return 0;
}

int isPresent(int *arr,int n)
{
    int i,count;
    for(i=0,count=0;i<MAX;i++)
    {
	if(arr[i]==1)
	    count++;
	else
	    count=0;
	if(count==n)
	    break;
    }
    if(count<n)
	return -1;
    return i;
}

void isMirror(int *arr)
{
    for(int i=0;i<10;arr[i]=0,i++);
    for(int i=10;i<MAX;i++)
    {
	int brk=0;
	for(int val=i;val;val/=10)
	    if(val%10==2||val%10==3||val%10==4||val%10==5||val%10==7)
		brk=1;
	brk?arr[i]=0:arr[i]=1;
    }
}

void printMirror(int index,int n,int *arr)
{
    for(int i=0;i<n;i++)
    {
	for(int val=index-i;val;val/=10)
	{
	    char c;
	    c=val%10+'0';
	    val%10==6?c='9':c;
	    val%10==9?c='6':c;
	    std::cout<<c;
	}
	std::cout<<" ";
    }
    std::cout<<"\n";
}
