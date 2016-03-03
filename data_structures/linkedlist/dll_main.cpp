#include<iostream>
#include"double_linked_list.h"
using namespace std;
int main()
{
	List dllist;
	dllist.addToTail(10);
//	dllist.addToTail(20);
//	dllist.addToHead(30);
//	dllist.addToHead(40);
	dllist.displayListHead();
	dllist.displayListTail();
	return 0;
}
