#include<iostream>
#define K 3
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
//				cout<<"Deleting "<<head->data<<endl;
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
		void printStack()
		{
			for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
				cout<<ptr->data<<" ";
			cout<<"\n";
		}
		Node *head;
};

void hanoi(Stack *stk,int x,int y,int N)
{
	if(N==0)
		return;

	int z=((y+1)%K==x?(y-1)%K:(y+1)%K);
	hanoi(stk,x,z,N-1);
	stk[y].push(stk[x].pop());
	hanoi(stk,z,y,N-1);
}

int main()
{
	int N;
	cin>>N;

	Stack stk[3];
	for(int i=N;i>=1;i--)
		stk[0].push(i);

	for(int i=0;i<K;i++)
		stk[i].printStack();

	hanoi(stk,0,1,N);

	for(int i=0;i<K;i++)
		stk[i].printStack();

	return 0;
}
