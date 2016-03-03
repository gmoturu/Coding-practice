#include<iostream>
#include"stack.h"
#include"queue.h"
#include"tree.h"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
using namespace std;
int main()
{
	Tree<int> tre;
	tre.insert(60);
	tre.insert(35);
	tre.insert(76);
	tre.insert(21);
	tre.insert(42);
	tre.insert(71);
	tre.insert(17);
	tre.insert(24);
	tre.insert(68);
	tre.insert(11);
	tre.insert(25);
	tre.insert(63);
	tre.insert(69);
	tre.insert(89);
	tre.inorderRecursive();
	tre.findDeleteCopying(60);
	tre.inorderIterative();
/*	tre.findDeleteMerging(89);
	tre.inorderRecursive();
	tre.findDeleteMerging(71);
	tre.inorderRecursive();
	tre.findDeleteMerging(24);
	tre.inorderRecursive();*/
	return 0;
}
