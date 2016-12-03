template <class S> class Stack
{
	public:
		class SNode
		{
			public:
				SNode()
				{
					next=NULL;
				}
				SNode(S idata,SNode *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				S data;
				SNode *next;
		};
		Stack()
		{
			head=NULL;
		}
		~Stack()
		{
			for(SNode *ptr;!isStackEmpty();)
			{
				ptr=head->next;
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
			head=new SNode(idata,head);
		}
		S pop()
		{
			S val=head->data;
			SNode *ptr=head;
			head=head->next;
			delete ptr;
			return val;
		}
		SNode *head;
};
