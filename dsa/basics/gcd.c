#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("GCD is %d\n",gcd(a,b));
    return 0;
}

int gcd(int a,int b)
{
    a<0?a=-a:a;
    b<0?b=-b:b;
    if (b==0)
	return a;
    gcd(b,a%b);
}
