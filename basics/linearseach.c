#include<stdio.h>
int main()
{
    int N=13;
    int num;
    int A[13]={10,5,12,2,8,4,6,1,3,9,13,11,7};
    scanf("%d",&num);
    findElement(A,num,N)<0?printf("Element not found\n"):printf("Number found\n");
    return 0;
}

int findElement(int *A,int num,int N)
{
    int i;
    for(i=0;i<N;i++)
	if (*(A+i)==num)
	    return i;
    return -1;
}
