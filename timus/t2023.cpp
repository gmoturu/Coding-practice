#include<iostream>
#include<string>
#define H 500
#define A 10
#define S 9
void createHash(std::string *,int,int *);
int evalHash(std::string,int *);
using namespace std;
int main()
{
    int *hash=new int[H];
    std::string casea[S]={"Alice","Ariel","Aurora",
			  "Phil","Peter","Olaf",
			  "Phoebus","Ralph","Robin"};
    std::string caseb[S]={"Bambi","Belle","Bolt",
			  "Mulan","Mowgli","Mickey",
			  "Silver","Simba","Stitch"};
    std::string casec[S]={"Dumbo","Genie","Jiminy",
			  "Kuzko","Kida","Kenai",
			  "Tarzan","Tiana","Winnie"};


    createHash(casea,1,hash);
    createHash(caseb,2,hash);
    createHash(casec,3,hash);

    int n;
    std::cin>>n;
    std::cin.ignore();
    string str_inp;

    int steps=0;
    for(int i=0,curr_case=1,next_case;i<n;i++)
    {
	std::cin>>str_inp;
	next_case=evalHash(str_inp,hash);
	(next_case-curr_case<0)?steps+=curr_case-next_case:steps+=next_case-curr_case;
	curr_case=next_case;
    }

    std::cout<<steps<<std::endl;

    delete[] hash;
    return 0;
}

void createHash(std::string *str,int val,int *hash)
{
    for(int i=0;i<S;i++)
    {
	const char *cstr=str[i].c_str();
	int sum=*cstr;
	for(;*cstr;cstr++)
	    sum+=*cstr;
	sum+=-400;
	hash[sum]=val;
    }
}

int evalHash(std::string str,int *hash)
{
    const char *cstr=str.c_str();
    int sum=*cstr;
    for(const char *cstr=str.c_str();*cstr;cstr++)
	sum+=*cstr;
    sum+=-400;
    return hash[sum];
}
