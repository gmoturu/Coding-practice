#include<iostream>
#define K 5
using namespace std;
int lsearch(int *,int);
int main()
{
  int a[K];
  for(int i=0;i<K;i++)
    cin>>a[i];
  int val;
  cin>>val;
  cout<<lsearch(a,val)<<endl;
  return 0;
}

int lsearch(int *a,int val)
{
//for(int i=0;i<K;i++) //checks all the list items
  for(int i=0;a[i]<=val;i++) //checks till the list is elements are less than the value in a sorted list
    if(val==a[i])
      return i;
  return -1;
}
