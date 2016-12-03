#include<iostream>
#include"single_linked_list.h"
using namespace std;
int main()
{
	List sslist;
	sslist.isListEmpty()?cout<<"YES\n":cout<<"NO\n";
	sslist.deleteHead();
	sslist.addToTail(1);
	sslist.addToHead(2);
	sslist.displayList();
	sslist.addToTail(3);
	sslist.displayList();
	sslist.addToHead(4);
	sslist.displayList();
	sslist.deleteHead();
	sslist.displayList();
	return 0;
}
