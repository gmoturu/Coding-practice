using namespace std;

template <class SL> class SList
{
	public:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(SL idata,Node *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				SL data;
				Node *next;
		};
		SList()
		{
			head=tail=NULL;
		}
		~SList()
		{
			for(Node *ptr;!isListEmpty();)
			{
				ptr=head->next;
				cout<<"Deleting "<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		bool isListEmpty()
		{
			return head==NULL;
		}
		void addToHead(SL idata)
		{
			head=new Node(idata,head);
			if(tail==NULL)
				tail=head;
		}
		void addToTail(SL idata)
		{
			if(tail==NULL)
				head=tail=new Node(idata);
			else
			{
				tail->next=new Node(idata);
				tail=tail->next;
			}
		}
		void addToTail_NoTailPtr(SL idata)
		{
			Node *ptr=head;
			if(ptr==NULL)
				head=tail=new Node(idata); //since this class has tail pointer
			else
			{
				for(;ptr->next!=NULL;ptr=ptr->next);
				ptr->next=new Node(idata);
				tail=ptr->next;
			}
		}
		void deleteFromHead()
		{
			if(head==NULL)
				return;
			else
			{
				Node *ptr=head->next;
				cout<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		void deleteFromTail()
		{
			if(tail==NULL)
				return;
			else if(head==tail)
			{
				cout<<tail->data<<endl;
				delete tail;
				head=tail=NULL;
			}
			else
			{
				Node *ptr;
				for(ptr=head;ptr->next!=tail;ptr=ptr->next);
				cout<<tail->data<<endl;
				delete tail;
				ptr->next=NULL;
				tail=ptr;
			}
		}
		void deleteFromTail_NoTailPtr()
		{
			if(head==NULL)
				return;
			else if(head->next==NULL)
			{
				cout<<head->data<<endl;
				delete head;
				head=tail=NULL;
			}
			else
			{
				Node *ptr;
				for(ptr=head;ptr->next->next!=NULL;ptr=ptr->next);
				cout<<ptr->next->data<<endl;
				delete ptr->next;
				ptr->next=NULL;
				tail=ptr;
			}
		}
		void deleteNodeWithVal(SL idata)
		{
			for(Node *ptr=head,*prev=NULL;ptr!=NULL;prev=ptr,ptr=ptr->next)
			{
				if(ptr->data==idata)
				{
					if(head==tail)
					{
						delete head;
						head=tail=NULL;
						return;
					}
					else if(ptr==head)
					{
						head=ptr->next;
						delete ptr;
						ptr=head;
					}
					else if(ptr==tail)
					{
						prev->next=NULL;
						delete ptr;
						tail=prev;
						return;
					}
					else
					{
						prev->next=ptr->next;
						delete ptr;
						ptr=prev->next;
					}
				}
			}
		}
		void displayList()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				cout<<ptr->data<<" ";
			cout<<"\n";
		}
		bool isElementInList(SL idata)
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				if(ptr->data==idata)
					return 1;
			return 0;
		}
		void insertAfterNth(int pos,SL idata)
		{
			if(pos==0)
				addToHead(idata);
			else
			{
				Node *ptr;
				int i;
				for(ptr=head,i=1;i!=pos && ptr!=NULL;i++,ptr=ptr->next);
				if(ptr!=NULL)
				{
					ptr->next=new Node(idata,ptr->next);
					if(ptr==tail)
						tail=ptr->next;
				}
				else
					cout<<"List does not have enough elements\n";
			}
		}
		int countElements()
		{
			int i=0;
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next,i++);
			return i;
		}
		void deleteNth(int pos)
		{
			if(pos<1 || pos>countElements())
				return;
			else if(pos==1)
				deleteFromHead();
			else if(pos==countElements())
				deleteFromTail();
			else
			{
				int i=1;
				Node *ptr,*prev;
				for(ptr=head,prev=NULL;i<pos;prev=ptr,ptr=ptr->next,i++);
				prev->next=ptr->next;
				delete ptr;
			}
		}
		void reverseList()
		{
			if(head==tail)
				return;
			else
			{
				Node *ptr,*tmp;
				for(tmp=NULL;head!=NULL;)
				{
					ptr=head->next;
					head->next=tmp;
					if(tmp==NULL)
						tail=head;
					tmp=head;
					head=ptr;
				}
				head=tmp;
			}
		}
		void deleteNthFromTail(int pos)
		{
			//Tail node is 1 from end. Head node is 1 from beginning
			int num=countElements();
			if(num-pos+1<1 || num-pos+1>num)
				return;
			else if(num-pos+1==1)
				deleteFromHead();
			else if(num-pos+1==num)
				deleteFromTail();
			else
			{
				int i=1;
				Node *ptr,*prev;
				for(ptr=head,prev=NULL;i<num-pos+1;prev=ptr,ptr=ptr->next,i++);
				prev->next=ptr->next;
				delete ptr;
			}
		}
		Node *head,*tail;
};
