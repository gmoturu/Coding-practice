#include<stdio.h>
double sqrtFunc(double,double);
int main()
{
  int num;
  scanf("%d",&num);
  printf("%lf\n",sqrtFunc(num,1));
  return 0;
}

double sqrtFunc(double num,double val)
{
  double newval=0.5*(val+num/val);
  double diff=val-newval;
  if(diff>0.005||diff<-0.005)
    return sqrtFunc(num,newval);
  return newval;
}
  
