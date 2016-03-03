#include<iostream>
#define K 101
void countingsort(int *,int *,int *,int *,int);
using namespace std;
int main()
{
    int N;
    std::cin>>N;

    int *teamid = new int[N];
    int *solved = new int[N];

    for(int i=0;i<N;i++)
	std::cin>>*(teamid+i)>>*(solved+i);

    int *teamid_sorted = new int[N];
    int *solved_sorted = new int[N];

    countingsort(teamid,solved,teamid_sorted,solved_sorted,N);

    delete teamid;
    delete solved;
    delete teamid_sorted;
    delete solved_sorted;

    return 0;
}

void countingsort(int *teamid,int *solved,int *teamid_sorted,int *solved_sorted,int N)
{
    int c_array[K];
    for(int i=0;i<K;i++)
	c_array[i]=0;
    for(int i=0;i<N;i++)
	c_array[K-1-solved[i]]++;
    for(int i=K-1;i>0;i--)
	c_array[i-1]=c_array[i]+c_array[i-1];
    for(int i=0;i<N;i++)
    {
	solved_sorted[N-c_array[K-1-solved[i]]]=solved[i];
	teamid_sorted[N-c_array[K-1-solved[i]]]=teamid[i];
	c_array[K-1-solved[i]]--;
    }
    for(int i=0;i<N;i++)
	std::cout<<teamid_sorted[i]<<" "<<solved_sorted[i]<<std::endl;

}
