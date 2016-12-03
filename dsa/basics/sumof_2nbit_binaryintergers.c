#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N=5;
    int A[5]={1,0,1,1,0};
    int B[5]={0,1,1,0,0};
    int C[6]={0};
    int i,carry=0;
    for(i=0;i<N;i++)
	printf("%d ",A[i]);
    printf("\n");
    for(i=0;i<N;i++)
        printf("%d ",B[i]);
    printf("\n");
    for(i=0;i<N;i++)
    {
	switch (carry+A[i]+B[i])
	{
	    case 0:
		C[i]=0;
		break;
	    case 1:
		C[i]=1;
		break;
	    case 2:
		C[i]=0;
		carry=1;
		break;
	    case 3:
		C[i]=1;
		carry=1;
		break;
	}
    }
    for(i=0;i<N+1;i++)
	printf("%d ",C[i]);
    printf("\n");
    printf("%d\n",sizeof(A)/sizeof(int));
    return 0;
}
