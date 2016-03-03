#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;

	N==0?cout<<"1"<<endl:N<0?cout<<-(-N*(-N+1))/2+1<<endl:cout<<(N*(N+1))/2<<endl;
	
	return 0;
}
