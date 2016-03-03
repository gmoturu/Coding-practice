#include<iostream>
using namespace std;

class Stack
{
	public:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(int idata,Node *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				int data;
				Node *next;
		};
		Stack()
		{
			head=NULL;
		}
		~Stack()
		{
			for(Node *ptr;!isStackEmpty();)
			{
				ptr=head->next;
//				cout<<"Deleting "<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		bool isStackEmpty()
		{
			return head==NULL;
		}
		void push(int idata)
		{
			head=new Node(idata,head);
		}
		int pop()
		{
			int val=head->data;
			Node *ptr=head->next;
			delete head;
			head=ptr;
			return val;
		}
		Node *head;
};

class Tree
{
	public:
		class Node
		{
			public:
				Node()
				{
					left=right=NULL;
				}
				Node(int idata,Node *ileft=NULL,Node *iright=NULL)
				{
					data=idata;
					left=ileft;
					right=iright;
				}
				int data;
				Node *left;
				Node *right;
		};
		Tree()
		{
			root=NULL;
		}
		~Tree()
		{
			if(root!=NULL)
				deleteTree(root);
		}
		void deleteTree(Node *ptr)
		{
			if(ptr->left!=NULL)
				deleteTree(ptr->left);
			if(ptr->right!=NULL)
				deleteTree(ptr->right);
//			cout<<"Deleting "<<ptr->data<<endl;
			delete ptr;
		}
		void addElement(int idata)
		{
//			cout<<idata<<endl;
			if(root==NULL)
				root=new Node(idata);
			else
				addElement(root,idata);
		}
		void addElement(Node *ptr,int idata)
		{
			if(ptr->data<idata)
			{
				if(ptr->right!=NULL)
					addElement(ptr->right,idata);
				else
					ptr->right=new Node(idata);
			} else {
				if(ptr->left!=NULL)
					addElement(ptr->left,idata);
				else
					ptr->left=new Node(idata);
			}
		}
		void postOrder()
		{
			if(root!=NULL)
				postOrder(root);
		}
		void postOrder(Node *ptr)
		{
			if(ptr->right!=NULL)
				postOrder(ptr->right);
			if(ptr->left!=NULL)
				postOrder(ptr->left);
			cout<<ptr->data<<endl;
		}
		Node *root;
};

int main()
{
	int N;
	Stack stk;
	Tree tre;
	int input;

	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>input;
		stk.push(input);
	}

	while(!stk.isStackEmpty())
		tre.addElement(stk.pop());

	tre.postOrder();

	return 0;
}
