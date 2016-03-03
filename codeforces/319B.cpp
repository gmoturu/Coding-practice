#include<iostream>
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
using namespace std;
bool isArrayIncreasing(int *,int);
/*
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
				Node(int idata,Node *inext=NULL)
				{
					data=idata;
					next=inext;
				}
				int data;
				Node *next;
		};
		List()
		{
			head=NULL;
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
		void insertToTail(int idata)
		{
			if(head==NULL)
				head=tail=new Node(idata);
			else
			{
				tail->next=new Node(idata);
				tail=tail->next;
			}
		}
		bool isListEmpty()
		{
			return head==NULL;
		}
		void displayList()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				cout<<ptr->data<<" ";
			cout<<"\n";
		}
		bool isListIncreasing()
		{
			int prev=head->data;
			for(Node *ptr=head->next;ptr!=NULL;ptr=ptr->next)
			{
				if(prev>ptr->data)
					return 0;
				prev=ptr->data;
			}
			return 1;
		}
		int listLength()
		{
			int length=0;
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next,length++);
			return length;
		}
		void killPsycho()
		{
			for(Node *ptr=head;ptr->next!=NULL;)
			{
				if(ptr->data>ptr->next->data)
				{
					Node *tmp=ptr->next;
					ptr->next=tmp->next;
					if(ptr->next!=NULL && tmp->data<ptr->next->data)
						ptr=ptr->next;
					delete tmp;
				}
				else
					ptr=ptr->next;
			}
		}
		Node *head,*tail;
};

int main()
{
	List lst;
	int n;
	cin>>n;

	for(int inp,i=1;i<=n;i++)
	{
		cin>>inp;
		lst.insertToTail(inp);
	}

	int iterations=0;
	for(;lst.listLength()>1 && !lst.isListIncreasing();iterations++)
		lst.killPsycho();
	cout<<iterations<<endl;

	return 0;
}
*/

int main()
{
	int N;
	cin>>N;

	int *arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>*(arr+i);

	int iterations=0;
	for(;!isArrayIncreasing(arr,N);iterations++)
	{
		int prev=arr[0];
		for(int i=1;i<N;i++)
		{
			if(arr[i]<=prev)
			{
				prev=arr[i];
				arr[i]=arr[i-1];
			}
			else
				prev=arr[i];
		}
	}
	cout<<iterations<<endl;

	delete [] arr;
	return 0;
}

bool isArrayIncreasing(int *arr,int N)
{
	for(int i=1;i<N;i++)
		if(arr[i]<arr[i-1])
			return 0;
	return 1;
}
