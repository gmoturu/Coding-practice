template <class Q> class Queue
{
	public:
		class QNode
		{
			public:
				QNode()
				{
					next=NULL;
				}
				QNode(Q idata,QNode *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				Q data;
				QNode *next;
		};
		Queue()
		{
			head=tail=NULL;
		}
		~Queue()
		{
			for(QNode *ptr;!isQueueEmpty();)
			{
				ptr=head->next;
				delete head;
				head=ptr;
			}
		}
		bool isQueueEmpty()
		{
			return head==NULL;
		}
		void enq(Q idata)
		{
			if(tail==NULL)
				head=tail=new QNode(idata);
			else
			{
				tail->next=new QNode(idata);
				tail=tail->next;
			}
		}
		Q deq()
		{
			Q val=head->data;
			QNode *tmp=head;
			if(head==tail)
				head=tail=NULL;
			else
				head=head->next;
			delete tmp;
			return val;
		}
		QNode *head,*tail;
};
