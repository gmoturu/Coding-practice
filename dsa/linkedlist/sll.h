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
		void displayList()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				std::cout<<ptr->data<<" ";
			std::cout<<"\n";
		}
		bool isElementInList(int val)
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				if(ptr->data==val)
					return 1;
			return 0;
		}
		void addToHead(int val)
		{
			head=new Node(val,head);
			if(tail==NULL)
				tail=head;
		}
		void addToTail(int val)
		{
			if(tail==NULL)
				head=tail=new Node(val);
			else
			{
				Node *ptr;
				for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
				ptr->next=new Node(val);
				tail=ptr->next;
			}
		}
		void deleteHead()
		{
			Node *ptr=head;
			if(head==tail)
				head=tail=NULL;
			else
				head=head->next;
			delete ptr;
		}
		void deleteTail(){}
		void addAfterNth(){}
		void deleteNth(){}
	private:
		Node *head,*tail;
};
