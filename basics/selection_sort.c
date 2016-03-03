#include<stdio.h>
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
void selectionSortAscending(int *,int);
void selectionSortDescending(int *,int);
void swapIntegers(int *,int *);
int main()
{
    int N=14;
    int A[14]={10,5,2,12,8,14,6,1,3,9,13,11,7,4};
    selectionSortAscending(A,N);
    int i; 
    printf("*******************************\n");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    selectionSortDescending(A,N);
    printf("*******************************\n");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void selectionSortAscending(int *A,int N)
{
    int i,index,j;
    for(i=0;i<N-1;i++)
    {
    	index=findMin(A,i,N);
	if(index>-1)
	    SWAP(*(A+i),*(A+index));
    }
}

void selectionSortDescending(int *A,int N)
{
    int i,index;
    for(i=0;i<N-1;i++)
    {
        index=findMax(A,i,N);
	if(index>-1)
	    SWAP(*(A+i),*(A+index));
    }
}

int findMin(int *A,int i,int N)
{
    int min=*(A+i),k;
    int index=-1;
    for(k=i+1;k<N;k++)
	if (min>*(A+k))
	{
	    min=*(A+k);
	    index=k;
	}
    return index;
}

int findMax(int *A,int i,int N)
{
    int max=*(A+i),k;
    int index=-1;
    for(k=i+1;k<N;k++)
        if (max<*(A+k))
        {
            max=*(A+k);
            index=k;
        }
    return index;
}
