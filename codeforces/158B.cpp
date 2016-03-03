#include<iostream>
using namespace std;
int main()
{
    // get the number of groups
    unsigned n;
    std::cin>>n;

    // get the array of groups
    unsigned *s = new unsigned[n];
    for(int i=0;i<n;i++)
	std::cin>>*(s+i);

    // count the number of each group
    int grp4,grp3,grp2,grp1,i;
    for(i=0,grp4=0,grp3=0,grp2=0,grp1=0;i<n;i++)
	s[i]==4?grp4++:s[i]==3?grp3++:s[i]==2?grp2++:s[i]==1?grp1++:i;

    // find the least number of cars
    unsigned num=0;
    num+=grp4+grp3+grp2/2;
    grp2%2?num+=1:num;
    (grp1-grp3-2*(grp2%2))>0?num+=(grp1-grp3-2*(grp2%2))/4:num;
    (grp1-grp3-2*(grp2%2)>0) && ((grp1-grp3-2*(grp2%2))%4)?num+=1:num;

    std::cout<<num<<std::endl;
    delete s;

    return 0;
}
