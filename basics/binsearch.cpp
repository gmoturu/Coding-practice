#include<iostream>
#define K 5
using namespace std;
int bsearch(int *,int);
int main()
{
  int a[K],item;
  for(int i=0;i<K;i++)
    cin>>a[i];
  cin>>item;
  cout<<bsearch(a,item)<<endl;
  return 0;
}

int bsearch(int *a,int item)
{
  bool found=0;
  int first=0;
  int last=K-1;
  int index=-1;
  while(first<=last && !found)
  {
    int mid=(first+last)/2;
    if(item<a[mid])
      last=mid-1;
    else if(a[mid]<item)
      first=mid+1;
    else
    {
      found=1;
      index=mid;
    }
  }
  return index;
}
