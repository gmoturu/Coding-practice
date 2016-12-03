using namespace std;

template <class Q>
class Queue
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
				cout<<"Deleting "<<head->data<<endl;
				delete head;
				head=ptr;
			}
		}
		bool isQueueEmpty()
		{
			return head==NULL;
		}
		void enqueue(Q idata)
		{
			if(head==NULL)
				head=tail=new QNode(idata);
			else
			{
				tail->next=new QNode(idata);
				tail=tail->next;
			}
		}
		Q dequeue()
		{
			Q val=head->data;
			QNode *ptr=head;
			head=head->next;
			delete ptr;
			return val;
		}
		QNode *head,*tail;
};
