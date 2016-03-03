#include<iostream>
#include<climits>
#define SIZE 2440
using namespace std;

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
                Node(string iname,Node *inext=NULL)
                {
                    name=iname;
                    next=inext;
                }
                string name;
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
        void enqueue(string iname)
        {
            if(tail==NULL)
                head=tail=new Node(iname);
            else
            {
                tail->next=new Node(iname);
                tail=tail->next;
            }
        }
        string dequeue()
        {
            string val=head->name;
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
				Node(string imember,Node *inext=NULL)
				{
					member=imember;
					next=inext;
				}
				string member;
				Node *next;
		};
		Graph()
		{
			for(int i=0;i<SIZE;i++)
			{
				name[i]="";
				distance[i]=INT_MAX;
				head[i]=NULL;
			}
		}
		~Graph()
		{
			for(int i=0;i<SIZE;i++)
			{
				for(Node *ptr;!isListEmpty(head[i]);)
				{
					ptr=head[i]->next;
//					cout<<"Deleting edge "<<name[i]<<" "<<head[i]->member<<endl;
					delete head[i];
					head[i]=ptr;
				}
			}
		}
		bool isListEmpty(Node *ptr)
		{
			return ptr==NULL;
		}
		void addEdge(string iname,string imember)
		{
			int index=getIndex(iname);
			name[index]=iname;
			head[index]=new Node(imember,head[index]);
		}
		int getIndex(string iname)
		{
			const char *str=iname.c_str();
			int index=0;
			for(;*str!='\0';str++)
				index+=*str;
			return index;
		}
		void breadthFS(string str)
		{
			Queue que;
			int old_hash=getIndex(str);
			que.enqueue(str);
			distance[old_hash]=0;
			while(!que.isQueueEmpty())
			{
				str=que.dequeue();
				old_hash=getIndex(str);
				for(Node *ptr=head[old_hash];ptr!=NULL;ptr=ptr->next)
				{
					int new_hash=getIndex(ptr->member);
					if(distance[new_hash]>distance[old_hash]+1)
					{
						que.enqueue(ptr->member);
						distance[new_hash]=distance[old_hash]+1;
					}
				}
			}
		}
		void printOutput()
		{
			for(int i=0;i<SIZE;i++)
				if(name[i]!="")
					if(distance[i]!=INT_MAX)
						cout<<name[i]<<" "<<distance[i]<<endl;
					else
						cout<<name[i]<<" undefined"<<endl;
		}
		string name[SIZE];
		int distance[SIZE];
		Node *head[SIZE];
};

int main()
{
	Graph gr;
	int n;
	cin>>n;

	string imember1,imember2,imember3;
	for(int i=0;i<n;i++)
	{
		cin>>imember1>>imember2>>imember3;
		gr.addEdge(imember1,imember2);
		gr.addEdge(imember2,imember1);
		gr.addEdge(imember2,imember3);
		gr.addEdge(imember3,imember2);
		gr.addEdge(imember1,imember3);
		gr.addEdge(imember3,imember1);
	}

	gr.breadthFS("Isenbaev");
	gr.printOutput();

	return 0;
}
