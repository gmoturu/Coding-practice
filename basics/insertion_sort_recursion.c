#include<stdio.h>
void insertionSort(int *,int);
void sort(int *,int,int);
int main()
{
    int N=13;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
    int i;
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    insertionSort(A,N-1);
    printf("*******************************\n");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void insertionSort(int *A,int end)
{
    int i,N=13;
    if(end>0)
    {
	insertionSort(A,end-1);
	sort(A,end-1,end);
    }
}

void sort(int *A,int before,int last)
{
    int key=*(A+last);
    while(*(A+before)>key && before>-1)
    {
	*(A+before+1)=*(A+before);
	before--;
    }
    *(A+before+1)=key;
}
