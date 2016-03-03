#include<iostream>
#include<string>
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
bool twoSubstring(std::string );
using namespace std;
int main()
{
	string strg;
	cin>>strg;

	twoSubstring(strg)?YES:NO;

	return 0;
}

bool twoSubstring(std::string strg)
{
	const char *cstr = strg.c_str();
	const char *beg=cstr;
	const char *end=cstr;
	for(;*end;end++);
	end--;
	for(;*beg;beg++)
		if( *beg=='A' && *(beg+1)=='B' )
			break;
	for(;end!=cstr;end--)
		if( *end=='A' && *(end-1)=='B' )
			break;
	cout<<beg<<endl;
	cout<<end<<endl;
	if( !*beg || end==cstr || beg==end || beg+1==end-1 )
		return 0;
	return 1;
}
