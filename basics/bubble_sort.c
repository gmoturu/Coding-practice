#include<stdio.h>
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
void bubbleSort(int *,int);
int main()
{
    int N=13;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
    int i;
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    bubbleSort(A,N);
    printf("*******************************\n");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

void bubbleSort(int *A,int N)
{
    int i,j;
    for(i=N-2;i>-1;i--)
	for(j=0;j<=i;j++)
	    if(*(A+j)>*(A+j+1))
		SWAP(*(A+j),*(A+j+1))
}
