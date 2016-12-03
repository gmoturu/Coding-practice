#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("LCM is %d\n",lcm(a,b));
    return 0;
}

int lcm(int a, int b)
{
    int res=(a*b)/gcd(a,b);
    res<0?res=-res:res;
    return res;
}

int gcd(int a,int b)
{
    a<0?a=-a:a;
    b<0?b=-b:b;
    if (!b)
	return a;
    gcd(b,a%b);
}
