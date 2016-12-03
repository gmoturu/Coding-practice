#include<iostream>
using namespace std;

int index_of_largest(int *A,int n)
{
  int answer(0);
  for(int i=1;i<n;i++)
  {
    if(A[i]>A[answer])
      answer=i;
  }
  return answer;
}

void selec(int *A,int n)
{
  for(int s=n;s>1;s--)
  {
    int p=index_of_largest(A,s);
    swap(A[s-1],A[p]);
  }
}

int main()
{
  int A[5];
  for(int i=0;i<5;i++)
    cin>>A[i];
  selec(A,5);
  for(int i=0;i<5;i++)
    cout<<A[i]<<" ";
  cout<<endl;
  return 0;
}
