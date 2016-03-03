#include<iostream>
#include<cmath>
using namespace std;

class Node
{
	public:
		Node()
		{
			next=NULL;
		}
		Node(unsigned long long ival,Node *inext=NULL)
		{
			val=ival;
			next=inext;
		}
		unsigned long long val;
		Node *next;
};

class List
{
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
				delete head;
				head=ptr;
			}
		}
		bool isListEmpty()
		{
			return head==NULL;
		}
		void findSqrt()
		{
			std::cout.precision(4);
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				std::cout<<std::fixed<<sqrt(ptr->val)<<std::endl;
		}
		void addToHead(unsigned long long ival)
		{
			head=new Node(ival,head);
		}
	private:
		Node *head;
};

int main()
{
	unsigned long long val;
	List num_list;
	while(std::cin>>val)
		num_list.addToHead(val);
	num_list.findSqrt();
	return 0;
}
