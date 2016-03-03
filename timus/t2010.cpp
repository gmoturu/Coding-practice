#include<iostream>
using namespace std;
int main()
{
	int sqr,x,y;
	std::cin>>sqr>>x>>y;

	int king=(x<sqr)+(x>1)+(y<sqr)+(y>1)+(x<sqr && y<sqr)+(x<sqr && y>1)+(x>1 && y<sqr)+(x>1 && y>1);
	int knight=(x<sqr-1 && y<sqr)+(x<sqr-1 && y>1)+(x<sqr && y<sqr-1)+(x>1 && y<sqr-1)+(x<sqr && y>2)+(x>1 && y>2)+(x>2 && y>1)+(x>2 && y<sqr);
	int rook=2*(sqr-1);
	int bishop=0;
	for(int i=x,j=y;i<sqr && j<sqr;i++,j++,bishop++);
	for(int i=x,j=y;i<sqr && j>1;i++,j--,bishop++);
	for(int i=x,j=y;i>1 && j<sqr;i--,j++,bishop++);
	for(int i=x,j=y;i>1 && j>1;i--,j--,bishop++);
	int queen=rook+bishop;
	std::cout<<"King: "<<king<<std::endl;
	std::cout<<"Knight: "<<knight<<std::endl;
	std::cout<<"Bishop: "<<bishop<<std::endl;
	std::cout<<"Rook: "<<rook<<std::endl;
	std::cout<<"Queen: "<<queen<<std::endl;

	return 0;
}
