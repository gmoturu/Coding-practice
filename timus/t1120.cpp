#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int N;
    std::cin>>N;

    int min_val=sqrt(N);
    min_val*min_val<N?min_val++:min_val;

    for(int i=min_val;i>0;i++)
    {
	if(N<=(i*(i-1))/2)
	    continue;
	std::cout<<(N-((i*(i-1))/2))/i<<" "<<i<<std::endl;
	break;
    }

//    std::cout<<min_val<<std::endl;
    return 0;
}
