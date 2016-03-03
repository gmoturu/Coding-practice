#include<cstdio>
#define MAX 1001
#define SZ 25
void getData(char *,int *,int *);
int convertInt(char *,char *);

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

class Stack
{
    public:
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
	void pop()
	{
	    if(head==NULL)
		return;
	    Node *ptr=head;
	    head=head->next;
	    printf("%d\n",ptr->data);
	    delete ptr;
	}
    private:
	Node *head;
};

int main()
{
    Stack *stk[MAX];
    for(int i=0;i<MAX;i++)
	stk[i]=NULL;

    int N,stknum,data;
    char input[SZ];
    scanf("%d",&N);
    getchar();

    for(int i=0;i<N;i++)
    {
	char *ptr=input;
	for(char ch;(ch=getchar())!='\n';ptr++)
	    *ptr=ch;
	*ptr='\0';
	for(ptr=input;*ptr!=' ';ptr++);
	getData(ptr+1,&stknum,&data);
	if(stk[stknum]==NULL)
	    stk[stknum]=new Stack;
	(*(input+1)=='U')?stk[stknum]->push(data):stk[stknum]->pop();
    }

    for(int i=0;i<MAX;i++)
	if(stk[i]!=NULL)
	    delete stk[i];
    return 0;
}

void getData(char *ptr,int *stknum,int *data)
{
    char *beg=ptr;
    char *end=ptr;
    for(;*end && *end!=' ';end++);
    *stknum=convertInt(beg,end);
    if(*end==' ')
    {
        beg=end+1;
        for(;*end;end++);
        *data=convertInt(beg,end);
    }
}

int convertInt(char *beg,char *end)
{
    int val=0;
    for(;beg<end;beg++)
    {
        val*=10;
        val+=*beg-'0';
    }
    return val;
}
