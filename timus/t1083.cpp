#include<iostream>
using namespace std;
int main()
{
    int n,k=0,last,res,diff;
    cin>>n;
    cin.ignore();
    for(char c;(c=cin.get())!='\n';k++);

    (n%k)!=0?last=n%k:last=k;
    res=n;
    for(res=n,diff=k;n-diff>=last;res*=n-diff,diff+=k);
    cout<<res<<endl;
    return 0;
}
