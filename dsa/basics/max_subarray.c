#include<stdio.h>
#include<limits.h>
int main()
{
    int i,N=16;
//    int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//    int A[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//    int A[16]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16};
    int A[16]={-1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,1};
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("Max subarry %d\n",kadane_algorithm(A,N));
    return 0;
}

int kadane_algorithm(int *A,int N)
{
    int max_sum=INT_MIN;
    int i;
    for(i=0;*(A+i)<0 && i<N;i++)
	if(max_sum<*(A+i))
	    max_sum=*(A+i);
    if(i==N)
	return max_sum;
    int sum;
    for(i=0,sum=0;i<N;i++)
    {
	if(*(A+i)+sum>-1)
	    sum+=*(A+i);
	else
	    sum=0;
	if(max_sum<sum)
	    max_sum=sum;
    }
    return max_sum;
}

int divide_conquer(int *A,int start,int end)
{
    if(start==end)
	return *(A+start);
    int mid=(end-start)/2;
    int left_mss=divide_conquer(A,start,start+mid);
    int right_mss=divide_conquer(A,start+mid+1,end);
    int left_sum=INT_MIN,right_sum=INT_MIN;
    int i,j,sum;
    for(i=start+mid,sum=0;i>=start;i--)
    {
	sum+=*(A+i);
	if(left_sum<sum)
	    left_sum=sum;
    }
    for(j=start+mid+1,sum=0;j<=end;j++)
    {
	sum+=*(A+j);
	if(right_sum<sum)
	    right_sum=sum;
    }
    //(a>b?a:b)>c?(a>b?a:b):c;
    sum=left_sum+right_sum;
    return (left_mss>right_mss?left_mss:right_mss)>sum?(left_mss>right_mss?left_mss:right_mss):sum; 
}

int bruteForce_On2(int *A,int N)
{
    int max_sum=INT_MIN;
    int i,j,sum;
    for(i=0;i<N;i++)
    {
        for(j=i,sum=0;j<N;j++)
        {
            sum+=*(A+j);
            if(max_sum<sum)
                max_sum=sum;
        }
    }
    return max_sum;
}

int bruteForce_On3(int *A,int N)
{
    int max_sum=INT_MIN;
    int i,j,k,iter,sum;
    for(i=1;i<=N;i++)
    {
	for(j=0;j<N;j++)
	{
	    for(iter=1,k=j,sum=0;j+i<=N && iter<=i;k++,iter++)
		sum+=*(A+k);
	    if(i+j>N)
		break; 
	    if(max_sum<sum)
		max_sum=sum;
	    sum=0;
	}
    }
    return max_sum;
}
