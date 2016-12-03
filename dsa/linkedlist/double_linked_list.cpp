#include<iostream>
#include"double_linked_list.h"
int main()
{
	DList<int> dll;
	dll.addToTail(10);
	dll.addToTail(20);
	dll.addToHead(30);
	dll.displayHead();
	dll.deleteFromTail();
	dll.displayTail();
	return 0;
}
