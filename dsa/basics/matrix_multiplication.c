#include<stdio.h>
void matrix_mul(int,int (*)[],int (*)[],int (*)[]);
int main()
{
    int A[3][3]={{3,-1,0},{2,5,1},{-7,1,3}};
    int B[3][3]={{6,-1,0},{0,1,-2},{3,-8,1}};
    int C[3][3]={{0}};
    int N=3,i,j;
    for(i=0;i<N;i++)
    {
	for(j=0;j<N;j++)
	    printf("%d ",A[i][j]);
	printf("\n");
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    matrix_mul(N,A,B,C);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}

void matrix_mul(int N,int (*A)[N],int (*B)[N],int (*C)[N])
{
    int i,j,k;
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				*(*(C+i)+j)+=*(*(A+i)+k) * *(*(B+k)+j);
}
