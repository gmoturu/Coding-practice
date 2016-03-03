#include<iostream>
#include<climits>
#include<cmath>
#define MAX 1001
#define SIDE 100
#define DIAG sqrt(20000)
#define DBL_MAX 1.79769e+300
using namespace std;

class List
{
	public:
		class Node
		{
			public:
				Node()
				{
					next=NULL;
				}
				Node(int ix,int iy,Node *inext=NULL)
				{
					x=ix;
					y=iy;
					next=inext;
				}
				int x;
				int y;
				Node *next;
		};
		List()
		{
			head=NULL;
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
		void insert(int ix,int iy)
		{
			head=new Node(ix,iy,head);
		}
		void printList()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				cout<<ptr->x<<" "<<ptr->y<<endl;
		}
		bool isListEmpty()
		{
			return head==NULL;
		}
		void remove()
		{
			Node *ptr=head->next;
			delete head;
			head=ptr;
		}
		void getTop(int *ix,int *iy)
		{
			*ix=head->x;
			*iy=head->y;
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
				Node(int ix,int iy,double iweight,Node *inext=NULL)
				{
					x=ix;
					y=iy;
					weight=iweight;
					next=inext;
				}
				int x;
				int y;
				double weight;
				Node *next;
		};
		Graph()
		{
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					head[i][j]=NULL;
					arr[i][j]=0;
				}
			}
		}
		~Graph()
		{
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					for(Node *ptr;!isListEmpty(head[i][j]);)
					{
						ptr=head[i][j]->next;
//						cout<<"Deleting "<<i<<" "<<j<<"    "<<head[i][j]->x<<" "<<head[i][j]->y<<"    "<<head[i][j]->weight<<endl;
						delete head[i][j];
						head[i][j]=ptr;
					}
				}
			}
		}
		bool isListEmpty(Node *ptr)
		{
			return ptr==NULL;
		}
		void createGrid(int N,int M)
		{
			for(int i=0;i<=N;i++)
			{
				for(int j=0;j<=M;j++)
				{
					if(i+1<=N)
						addEdge(i,j,i+1,j,SIDE);
					if(j+1<=M)
						addEdge(i,j,i,j+1,SIDE);
				}
			}
		}
		void addEdge(int a,int b,int c,int d,double iweight)
		{
			head[a][b]=new Node(c,d,iweight,head[a][b]);
		}
		void depthFS(Node *ptr,List *lst)
		{
			for(;ptr!=NULL;ptr=ptr->next)
			{
				if(arr[ptr->x][ptr->y]==0)
				{
					arr[ptr->x][ptr->y]=1;
					depthFS(head[ptr->x][ptr->y],lst);
					lst->insert(ptr->x,ptr->y);
				}
			}
		}
		void topologicalSort(int N,int M,List *lst)
		{
			arr[0][0]=1;
			depthFS(head[0][0],lst);
		}
		void getShortest(int N,int M)
		{
			List lst;
			topologicalSort(N,M,&lst);
			lst.insert(0,0);

			double wgt[N][M];
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					wgt[i][j]=DBL_MAX;
			wgt[0][0]=0;

			int a,b;
			for(;!lst.isListEmpty();lst.remove())
			{
				lst.getTop(&a,&b);
				for(Node *ptr=head[a][b];ptr!=NULL;ptr=ptr->next)
					if(wgt[ptr->x][ptr->y]>wgt[a][b]+ptr->weight)
						wgt[ptr->x][ptr->y]=wgt[a][b]+ptr->weight;
			}

			cout<<roundf(wgt[N][M])<<endl;
		}
		double roundf(double number)
		{
			return number<0.0?ceil(number-0.5):floor(number+0.5);
		}
		bool arr[MAX][MAX];
		Node *head[MAX][MAX];
};

int main()
{
	Graph gr;
	int N,M,K,x,y;
	cin>>N>>M;

	gr.createGrid(N,M);

	cin>>K;
	for(int i=0;i<K;i++)
	{
		cin>>x>>y;
		gr.addEdge(x-1,y-1,x,y,DIAG);
	}

	gr.getShortest(N,M);

	return 0;
}
