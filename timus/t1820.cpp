#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;

    cout<<(n<k?2:(n*2)%k==0?(n*2)/k:(n*2)/k+1)<<endl;
    return 0;
}

