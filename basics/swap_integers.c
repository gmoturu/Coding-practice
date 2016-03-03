#include<stdio.h>
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    SWAP(a,b);
    printf("%d %d\n",a,b);
    return 0;
}
