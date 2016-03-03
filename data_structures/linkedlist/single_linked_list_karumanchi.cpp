#include<iostream>
using namespace std;

template <class L> class List
{
	private:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(L idata,Node *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				L data;
				Node *next;
		};
	public:
		List()
		{
			head=NULL;
		}
		~List()
		{
			for(Node *ptr;!isListEmpty();)
			{
				ptr=head->next;
				cout<<"Deleting "<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		Node *head;

		bool isListEmpty()
		{
			return head==NULL;
		}
		void insert(L idata)
		{
			head=new Node(idata,head);
		}
		L findNthFromEnd(int N)
		{
			Node *first=head;
			Node *secnd;
			int i;
			for(i=1;i<N && first!=NULL;first=first->next,i++);
			if(i<N)
				return -1;
			for(;first!=NULL;secnd=secnd->next,first=first->next);
			return secnd->data;
		}
};

int main()
{
	List<int> lst;
	lst.insert(10);
	lst.insert(30);
	lst.insert(40);
	lst.insert(20);
	cout<<lst.findNthFromEnd(2)<<endl;
	return 0;
}
