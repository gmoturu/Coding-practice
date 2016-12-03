#include<iostream>
using namespace std;

template <class S> class Stack
{
	public:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(S idata,Node *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				S data;
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
				cout<<"Deleting "<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		bool isStackEmpty()
		{
			return head==NULL;
		}
		void push(S idata)
		{
			head=new Node(idata,head);
		}
		S pop()
		{
			Node *ptr=head->next;
			S ret_val=head->data;
			delete head;
			head=ptr;
			return ret_val;
		}
		Node *head;
};

int main()
{
	Stack<int> stk;
	stk.push(10);
	stk.push(20);
	cout<<stk.pop()<<endl;
	return 0;
}
