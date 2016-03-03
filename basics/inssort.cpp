#include<iostream>
#define K 5
using namespace std;
void sort(int *);
int main()
{
  int a[K];
  for(int i=0;i<K;i++)
    cin>>a[i];
  sort(a);
  for(int i=0;i<K;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}

void sort(int *a)
{
  int nexte;
  for(int j=1;j<K;j++)
  {
    nexte=a[j];
    while(nexte>a[j-1] && j>0)
    {
      a[j]=a[j-1];
      j--;
    }
    a[j]=nexte;
  }
}
