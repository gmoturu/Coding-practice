// find all prime numbers upto n
#include<stdio.h>
#include<math.h>
int main()
{
    /* this is for small array size - also bad implementation*/
    int n=121;
    char A[121]={0};
    int i=2,j;
    for (i;i<n;i++)
	A[i]=1;
    for (i=2;i<sqrt(n);i++)
	if(A[i])
	    for(j=2*i;j<n;j+=i)
		A[j]=0;
    for(i=0;i<n;i++)
	if (A[i])
	    printf("%d\n",i);
    /* program ends here */
    return 0;
}
