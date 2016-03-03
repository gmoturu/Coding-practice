#include<iostream>
#define N 6
using namespace std;
int dynamic(int *,int *,int *,int *,int *,int *,int *,int *,int,int,int,int);
void recurs(int *,int *,int *,int *,int *,int *,int,int,int,int,int);
void printline(int *,int);
int main()
{
	// this program considers only 2 assembly lines
	int a1[N]={7,9,3,4,8,4};
	int a2[N]={8,5,6,4,5,7};
	int t1[N-1]={2,3,1,3,4};
	int t2[N-1]={2,1,2,2,1};
	int f1[N];
	int f2[N];
	int b1=2,b2=4;
	int e1=3,e2=2;

	int l1[N]={1};
	int l2[N]={2};

	int line=dynamic(a1,a2,t1,t2,l1,l2,f1,f2,b1,b2,e1,e2);

	recurs(a1,a2,t1,t2,l1,l2,b1,b2,e1,e2,N);

	(line==1)?printline(l2,line):printline(l1,line);

	return 0;
}

int dynamic(int *a1,int *a2,int *t1,int *t2,int *l1,int *l2,int *f1,int *f2,int b1,int b2,int e1,int e2)
{
	f1[0]=a1[0]+b1;
	f2[0]=a2[0]+b2;

	for(int j=1;j<N;j++)
	{
		if((f1[j-1]+a1[j])<(f2[j-1]+t2[j-1]+a1[j]))
		{
			f1[j]=f1[j-1]+a1[j];
			l1[j]=1;
		}
		else
		{
			f1[j]=f2[j-1]+t2[j-1]+a1[j];
			l1[j]=2;
		}

		if((f2[j-1]+a2[j])<(f1[j-1]+t1[j-1]+a2[j]))
		{
			f2[j]=f2[j-1]+a2[j];
			l2[j]=2;
		}
		else
		{
			f2[j]=f1[j-1]+t1[j-1]+a2[j];
			l2[j]=1;
		}
	}

	if((f1[N-1]+e1)<(f2[N-1]+e2))
		return 1;
	return 2;
}

void recurs(int *a1,int *a2,int *t1,int *t2,int *l1,int *l2,int b1,int b2,int e1,int e2,int j)
{
}

void printline(int *l,int line)
{
	for(int i=1;i<N;i++)
	{
		if(l[i]==1)
			cout<<"Line 1 : Station "<<i<<endl;
		else
			cout<<"Line 2 : Station "<<i<<endl;
	}
	cout<<"Line "<<line<<" : Station "<<N<<endl;
}
