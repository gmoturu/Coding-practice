using namespace std;

template <class DL> class DList
{
	public:
		class Node
		{
			public:
				Node()
				{
					prev=next=NULL;
				}
				Node(DL idata,Node *iprev=NULL,Node *inext=NULL)
				{
					data=idata;
					prev=iprev;
					next=inext;
				}
				DL data;
				Node *prev,*next;
		};
		DList()
		{
			head=tail=NULL;
		}
		~DList()
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
		void addToHead(DL idata)
		{
			if(head==NULL)
				head=tail=new Node(idata);
			else
			{
				head->prev=new Node(idata,NULL,head);
				head=head->prev;
			}
		}
		void addToTail(DL idata)
		{
			if(tail==NULL)
				head=tail=new Node(idata);
			else
			{
				tail->next=new Node(idata,tail);
				tail=tail->next;
			}
		}
		void displayHead()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				cout<<ptr->data<<" ";
			cout<<"\n";
		}
		void displayTail()
		{
			for(Node *ptr=tail;ptr!=NULL;ptr=ptr->prev)
				cout<<ptr->data<<" ";
			cout<<"\n";
		}
		void deleteFromHead()
		{
			if(head==NULL)
				return;
			else if(head==tail)
			{
				delete head;
				head=tail=NULL;
			}
			else
			{
				Node *ptr=head->next;
				delete head;
				ptr->prev=NULL;
				head=ptr;
			}
		}
		void deleteFromTail()
		{
			if(tail==NULL)
				return;
			else if(head==tail)
			{
				delete tail;
				head=tail=NULL;
			}
			else
			{
				Node *ptr=tail;
				tail->prev->next=NULL;
				tail=tail->prev;
				delete ptr;
			}
		}
		Node *head,*tail;
};





















