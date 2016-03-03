#include<iostream>
#include"tree.h"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
int main()
{
	Tree<int> tr;
	tr.insertElementIterative(60);
    tr.insertElementIterative(35);
    tr.insertElementIterative(76);
    tr.insertElementIterative(21);
    tr.insertElementIterative(42);
    tr.insertElementIterative(71);
    tr.insertElementIterative(17);
    tr.insertElementIterative(24);
    tr.insertElementIterative(68);
    tr.insertElementIterative(11);
    tr.insertElementIterative(25);
    tr.insertElementIterative(63);
    tr.insertElementIterative(69);
    tr.insertElementIterative(89);
	tr.inorderRecursive();
	cout<<tr.findLeaves()<<endl;
	cout<<tr.findFullNodes()<<endl;
//	tr.inorderIterative();
//	tr.preorderRecursive();
//	tr.preorderIterative();
//	tr.postorderRecursive();
///	tr.postorderIterative();
//	cout<<tr.findMaxBinaryTreeRecursion()<<endl;
//	cout<<tr.findMaxBinaryTreeIterative()<<endl;
//	tr.searchBinaryTreeRecursive(24)?YES:NO;
//	tr.searchBinaryTreeIterative(24)?YES:NO;
//	tr.insertBinaryTreeIterative(2);
//	tr.inorderRecursive();
//	tr.insertBinaryTreeRecursive(3);
//	tr.zigZagLevel();
//	tr.inorderRecursive();
//	cout<<tr.sizeRecursive()<<endl;
//	cout<<tr.heightRecursive()<<endl;
//	cout<<tr.heightIterative()<<endl;
//	cout<<tr.maximumRecursive()<<endl;
//	cout<<tr.minRecursive()<<endl;
//	tr.searchRecursive(100)?YES:NO;
//	tr.searchRecursive(42)?YES:NO;
//	tr.invertRecursive();
//	tr.inorderRecursive();
//	tr.bfsTopdownLeftright();
//	tr.bfsBottomupRightleft();
//	tr.lcaTree(21,35);
	return 0;
}
