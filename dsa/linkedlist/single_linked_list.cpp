#include<iostream>
#include"single_linked_list.h"
int main()
{
	SList<int> sll;
	sll.addToHead(10);
	sll.addToTail(20);
	sll.addToTail_NoTailPtr(30);
	sll.addToHead(40);
	sll.addToHead(10);
	sll.addToTail(10);
	sll.displayList();
	sll.deleteNthFromTail(4);
//	sll.reverseList();
	sll.displayList();
	return 0;
}
