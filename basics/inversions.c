#include<stdio.h>
#include<stdlib.h>
void inversion(int *,int,int);
void addInversions(int *,int,int,int);
static int total_inversions=0;
int main()
{
    int N=13,i;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
//    int A[13]={13,12,11,10,9,8,7,6,5,4,3,2,1};
//    int A[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    inversion(A,0,N-1);
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("Total inversions %d\n",total_inversions);
    return 0;
}

void inversion(int *A,int start,int end)
{
    if(start<end)
    {
	int mid=(end-start)/2;
	inversion(A,start,start+mid);
	inversion(A,start+mid+1,end);
	addInversions(A,start,start+mid,end);
    }
}

void addInversions(int *A,int start,int mid,int end)
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

    for(k=start;k<=end;k++)
    i=0;
    j=0;
    k=start;
    int arrsize=lsize;
    while(i<lsize && j<rsize)
    {
	if(*(L+i)>*(R+j))
	{
	    *(A+k)=*(R+j);
	    j++;
	    k++;
	    total_inversions+=arrsize;
	} else {
	    *(A+k)=*(L+i);
	    i++;
	    k++;
	    arrsize--;
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
