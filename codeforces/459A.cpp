#include<iostream>
void returnCoordinates(int,int,int,int);
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	std::cin>>x1>>y1>>x2>>y2;

	if(x2-x1==0 || y2-y1==0 || (x2-x1)==(y2-y1))
		returnCoordinates(x1,y1,x2,y2);
	else
		std::cout<<"-1\n";

	return 0;
}

void returnCoordinates(int x1,int y1,int x2,int y2)
{
	int x3,y3,x4,y4;
	if(x2-x1==0)
	{
		x3=x1+y2-y1;
		y3=y1;
		x4=x2+y2-y1;
		y4=y2;
	}
	else if(y2-y1==0)
	{
		x3=x1;
		y3=y1+x2-x1;
		x4=x2;
		y4=y2+x2-x1;
	}
	else
	{
		x3=x2;
		y3=y1;
		x4=x1;
		y4=y2;
	}
	std::cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
}
