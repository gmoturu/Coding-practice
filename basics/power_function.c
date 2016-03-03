#include<stdio.h>
double powFunc(double,int);
int main()
{
  double num;
  int rais;
  scanf("%lf %d",&num,&rais);
  printf("%lf\n",powFunc(num,rais));
  return 0;
}

double powFunc(double num,int p)
{
  if(p==1)
    return num;
  return num*powFunc(num,--p);
}
  
