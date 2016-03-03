#include<iostream>
#define TOWNS 10001
using namespace std;

class Stack
{
	public:
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
		Stack()
		{
			head=NULL;
		}
		~Stack()
		{
			for(Node *ptr;head!=NULL;)
            {
                ptr=head->next;
                delete head;
                head=ptr;
			}
		}
		void push(int idata)
		{
			head=new Node(idata,head);
		}
		int pop()
		{
			int val=head->data;
			Node *ptr=head->next;
			delete head;
			head=ptr;
			return val;
		}
		int getTop()
		{
			return head->data;
		}
		bool isStackEmpty()
		{
			return head==NULL;
		}
		Node *head;
};

class Queue
{
	public:
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
		Queue()
		{
			head=tail=NULL;
		}
		~Queue()
		{
			for(Node *ptr;head!=NULL;)
			{
				ptr=head->next;
				delete head;
				head=ptr;
			}
		}
		void enqueue(int idata)
		{
			if(tail==NULL)
				head=tail=new Node(idata);
			else
			{
				tail->next=new Node(idata);
				tail=tail->next;
			}
		}
		int dequeue()
		{
			int val=head->data;
			if(head==tail)
			{
				delete head;
				head=tail=NULL;
			}
			else
			{
				Node *ptr=head->next;
				delete head;
				head=ptr;
			}
			return val;
		}
		bool isQueueEmpty()
		{
			return head==NULL;
		}
		Node *head,*tail;
};

class Graph
{
	public:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(int ineighbor,bool iweight,Node *inext=NULL)
				{
					neighbor=ineighbor;
					weight=iweight;
					next=inext;
				}
				int neighbor;
				bool weight;
				Node *next;
		};
		Graph()
		{
			for(int i=0;i<TOWNS;i++)
				head[i]=NULL;
		}
		~Graph()
		{
			for(int i=0;i<TOWNS;i++)
			{
				for(Node *ptr;!isListEmpty(head[i]);)
				{
					ptr=head[i]->next;
					delete head[i];
					head[i]=ptr;
				}
			}
		}
		bool isListEmpty(Node *ptr)
		{
			return ptr==NULL;
		}
		void addEdge(int vertex_a,int vertex_b)
		{
			addEdge(vertex_a,vertex_b,1);
			addEdge(vertex_b,vertex_a,0);
		}
		void addEdge(int vertex_a,int vertex_b,bool iweight)
		{
			head[vertex_a]=new Node(vertex_b,iweight,head[vertex_a]);
		}
		void minGears(int vertex_a,int vertex_b)
		{
			bool visited[TOWNS];
			for(int i=0;i<TOWNS;i++)
				visited[i]=0;

			Queue curr_que,prev_que;
			Stack curr_stk,prev_stk;
			int val;
			curr_que.enqueue(vertex_a);
			prev_que.enqueue(0);
			visited[vertex_a]=1;

			while(!curr_que.isQueueEmpty())
			{
				int curr=curr_que.dequeue();
				int prev=prev_que.dequeue();
				curr_stk.push(curr);
				prev_stk.push(prev);

				for(Node *ptr=head[curr];ptr!=NULL;ptr=ptr->next)
				{
					if(visited[ptr->neighbor]==0)
					{
						curr_que.enqueue(ptr->neighbor);
						prev_que.enqueue(curr);
						visited[ptr->neighbor]=1;
					}
				}
			}

			while(curr_stk.getTop()!=vertex_b)
			{
				curr_stk.pop();
				prev_stk.pop();
			}

			int gears=-1;
			int prev,curr;
			while(!curr_stk.isStackEmpty())
			{
				curr=curr_stk.getTop();
				if(curr==prev || curr==vertex_a)
				{
					cout<<curr<<" ";
					gears++;
				}

				prev=prev_stk.getTop();
				curr_stk.pop();
				prev_stk.pop();
			}
//			cout<<gears<<endl;
			cout<<"\n";
		}
		Node *head[TOWNS];
};

int main()
{
	Graph gr;
	int n,m;
	cin>>n>>m;

	int vertex_a,vertex_b;
	for(int i=0;i<m;i++)
	{
		cin>>vertex_a>>vertex_b;
		gr.addEdge(vertex_a,vertex_b);
	}

	cin>>vertex_a>>vertex_b;
	gr.minGears(vertex_a,vertex_b);

	return 0;
}
