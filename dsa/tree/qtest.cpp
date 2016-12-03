#include<iostream>
#include"queue.h"
using namespace std;
int main()
{
	Queue<int> qu;
	qu.enq(10);
	qu.enq(20);
	cout<<qu.deq()<<endl;
	return 0;
}
