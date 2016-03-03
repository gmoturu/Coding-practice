#include<stdio.h>
void insertionSortAscending(int *,int);
void insertionSortDescending(int *,int);
int main()
{
    int N=13;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
    insertionSortAscending(A,N);
    int i;
    printf("*******************************\n");
    for(i=0;i<N;i++)
	printf("%d ",A[i]);
    printf("\n");
    insertionSortDescending(A,N);
    printf("*******************************\n");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    
    return 0;
}
void insertionSortAscending(int *A,int N)
{
    int i,j,temp,l;
    for(i=1;i<N;i++)
    {
	j=i-1;
	temp=*(A+i);
	while(j>-1 && *(A+j)>temp)
	{
	    *(A+j+1)=*(A+j);
	    j--;
	}
	*(A+j+1)=temp;
	for(l=0;l<N;l++)
	     printf("%d ",*(A+l));
	printf("\n");
    }
}
void insertionSortDescending(int *A,int N)
{
    int i,j,temp,l;
    for(i=1;i<N;i++)
    {
	temp=*(A+i);
	j=i-1;
	while(j>-1 && *(A+j)<temp)
	{
	    *(A+j+1)=*(A+j);
	    j--;
	}
	*(A+j+1)=temp;
	for(l=0;l<N;l++)
             printf("%d ",*(A+l));
        printf("\n");
    }
}
