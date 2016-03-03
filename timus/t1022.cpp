#include<iostream>
#define MAX 101
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
				Node(int ivertex,Node *inext=NULL)
				{
					vertex=ivertex;
					next=inext;
				}
				int vertex;
				Node *next;
		};
		Stack()
		{
			head=NULL;
		}
		~Stack()
		{
			for(Node *ptr;!isStackEmpty();)
			{
				ptr=head->next;
				cout<<"Deleting "<<head->vertex<<endl;
				delete head;
				head=ptr;
			}
		}
		bool isStackEmpty()
		{
			return head==NULL;
		}
		void push(int ivertex)
		{
			head=new Node(ivertex,head);
		}
		void pop()
		{
			Node *ptr=head->next;
			delete head;
			head=ptr;
		}
		int getTop()
		{
			return head->vertex;
		}
		Node *head;
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
				Node(int ineighbor,Node *inext=NULL)
				{
					neighbor=ineighbor;
					next=inext;
				}
				int neighbor;
				Node *next;
		};
		Graph()
		{
			for(int i=0;i<MAX;i++)
				head[i]=NULL;
		}
		~Graph()
		{
			for(int i=0;i<MAX;i++)
			{
				for(Node *ptr;!isListEmpty(head[i]);)
				{
					ptr=head[i]->next;
//					cout<<"Deleting "<<i<<" "<<head[i]->neighbor<<endl;
					delete head[i];
					head[i]=ptr;
				}
			}
		}
		bool isListEmpty(Node *ptr)
		{
			return ptr==NULL;
		}
		void addEdge(int i,int j)
		{
			head[i]=new Node(j,head[i]);
		}
		void depthFS()
		{
		}
		Node *head[MAX];
};

int main()
{
	Graph gr;
	int N,input;

	cin>>N;
	for(int i=1;i<=N;i++)
	{
		while(1)
		{
			cin>>input;
			if(input!=0)
				gr.addEdge(i,input);
			else
				break;
		}
	}

	gr.depthFS();

	return 0;
}
