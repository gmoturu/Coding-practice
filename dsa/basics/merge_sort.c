#include<stdio.h>
#include<stdlib.h>
void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int main()
{
    int N=13,i;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    mergeSort(A,0,N-1);
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

void mergeSort(int *A,int start,int end)
{
    if (start<end)
    {
	int mid=(end-start)/2;
        mergeSort(A,start,start+mid);
        mergeSort(A,start+mid+1,end);
	merge(A,start,start+mid,end);
    }
}

void merge(int *A,int start,int mid,int end)
{
    int *L,*R;
    int lsize=mid-start+1;
    int rsize=end-mid;
    L=malloc(lsize*sizeof(int));
    R=malloc(rsize*sizeof(int));
    int i,j,k;
    for(i=0;i<lsize;i++)
	*(L+i)=*(A+start+i);
    for(j=0;j<rsize;j++)
	*(R+j)=*(A+mid+1+j);

    i=0;
    j=0;
    k=start;
    while(i<lsize && j<rsize && k<=end)
    {
	if(*(L+i)<*(R+j))
	{
	    *(A+k)=*(L+i);
	    k++;
	    i++;
	}
	else 
	{
	    *(A+k)=*(R+j);
	    k++;
	    j++;
	}
    }
    for(;i<lsize;i++)
    {
	*(A+k)=*(L+i);
	k++;
    }
    for(;j<rsize;j++)
    {
        *(A+k)=*(R+j);
        k++;
    }

    free(L);
    free(R);
}
