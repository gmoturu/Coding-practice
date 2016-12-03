#include<stdio.h>
int main()
{
    int a=10,b=20,c=30;
    int max=(a>b?a:b)>c?(a>b?a:b):c;
    printf("%d\n",max);
    return 0;
}
