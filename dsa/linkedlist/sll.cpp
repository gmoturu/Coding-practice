#include<iostream>
using namespace std;

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

class List
{
	public:
		List()
		{
			head=tail=NULL;
		}
		~List()
		{
			for(Node *ptr;head!=NULL;)
			{
				ptr=head->next;
				delete head;
				head=ptr;
			}
		}
		void displayList()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				std::cout<<ptr->data<<" ";
			std::cout<<"\n";
		}
		bool isListEmpty()
		{
			return head==NULL;
		}
		void addToHead(int idata)
		{
			head=new Node(idata,head);
			if(tail==NULL)
				tail=head;
		}
		void addToTail(int idata)
		{
			if(tail==NULL)
				head=tail=new Node(idata);
			else
			{
				tail->next=new Node(idata);
				tail=tail->next;
			}
		}
		void deleteFromHead()
		{
			Node *ptr=head;
			if(head==NULL)
				return;
			if(head==tail)
				head=tail=NULL;
			else
				head=head->next;
			delete ptr;
		}
		void deleteFromTail()
		{
			if(tail==NULL)
				return;
			if(head==tail)
			{
				delete head;
				head=tail=NULL;
			}
			else
			{
				Node *ptr;
				for(ptr=head;ptr->next!=tail;ptr=ptr->next);
				delete tail;
				tail=ptr;
			}
		}
		void addAfterNth(int N,int idata)
		{
			if(head==NULL)
			{
				std::cout<<"Empty List\n";
				return;
			}
			Node *ptr;
			int count;
			for(ptr=head,count=1;count<N && ptr!=NULL;count++,ptr=ptr->next);
			if(count==N)
				ptr->next=new Node(idata,ptr->next);
			else
				std::cout<<"List has only "<<count<<" elements\n";
		}
		void deleteNth(int N)
		{
			if(head==NULL)
			{
				std::cout<<"Empty List\n";
				return;
			}
			if(N==1)
			{
				deleteFromHead();
				return;
			}
			Node *ptr;
			int count;
			for(ptr=head,count=1;count<N-1 && ptr!=NULL;count++,ptr=ptr->next);
			if(ptr==NULL)
			{
				std::cout<<"List does not have "<<N<<"th element\n";
				return;
			}
			Node *tmp=ptr->next;
			ptr->next=tmp->next;
			delete tmp;
		}
		void reverseList()
		{
			Node *tmp=NULL;
			for(Node *ptr;head!=NULL;)
			{
				ptr=head->next;
				head->next=tmp;
				tmp=head;
				head=ptr;
			}
			head=tmp;
		}
	private:
		Node *head,*tail;
};

int main()
{
	List sllist;
	sllist.displayList();
	sllist.addToTail(30);
	sllist.addToHead(40);
	sllist.addToTail(10);
	sllist.addToTail(20);
	sllist.addAfterNth(2,50);
	sllist.displayList();
	sllist.reverseList();
	sllist.displayList();
	return 0;
}
