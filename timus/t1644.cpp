#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int count,hun=2,sat=10;
    string eat;
    for(int i=0;i<n;i++)
    {
	cin>>count>>eat;
	eat.compare("hungry")==0?(count>hun?hun=count:hun):(count<sat?sat=count:sat);
    }
    sat<=hun?cout<<"Inconsistent\n":cout<<sat<<endl;
    return 0;
}
