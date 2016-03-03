#include<iostream>
#define K 5
#define Swap(a,b) {a=a^b;b=a^b;a=a^b;}
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
  int comp=K;
  while(--comp)
    for(int i=0;i<comp;i++)
      if(a[i]>a[i+1])
        Swap(a[i],a[i+1]);
}
