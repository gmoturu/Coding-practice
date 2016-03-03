#include<iostream>
#define SZ 30
int getHash(std::string);
using namespace std;

class Node
{
    public:
	Node()
	{
	    next=NULL;
	}
	Node(std::string istr,Node *inext=NULL)
	{
	    str=istr;
	    next=inext;
	}
	std::string str;
	Node *next;
};

class List
{
    public:
	List()
	{
	    head=NULL;
	}
	~List()
	{
	    for(Node *ptr;head!=NULL;)
	    {
		ptr=head->next;
//		std::cout<<"Deleting "<<head->str<<std::endl;
		delete head;
		head=ptr;
	    }
	}
	void push(std::string istr)
	{
	    head=new Node(istr,head);
	}
	bool isInList(std::string istr)
	{
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
		if(ptr->str.compare(istr)==0)
		    return 1;
	    return 0;
	}
	int listLength()
	{
	    int count=0;
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next,count++);
	    return count;
	}
    private:
	Node *head;
};

int main()
{
    int N;
    std::cin>>N;
    std::cin.ignore();

    List *lst[N];
    for(int i=0;i<N;i++)
	lst[i]=NULL;

    std:;string istr;
    for(int i=0;i<N;i++)
    {
	std::getline(std::cin,istr);
	int hash=getHash(istr)%N;
	if(lst[hash]==NULL)
	    lst[hash]=new List;
	if(!lst[hash]->isInList(istr))
	    lst[hash]->push(istr);
    }

    int sum=0;
    for(int i=0;i<N;i++)
	if(lst[i]!=NULL)
	    sum+=lst[i]->listLength();
    std::cout<<N-sum<<std::endl;

    for(int i=0;i<N;i++)
	if(lst[i]!=NULL)
	    delete lst[i];

    return 0;
}

int getHash(std::string str)
{
    int sum=0;
    for(const char *ptr=str.c_str();*ptr;ptr++)
	sum+=*ptr;
    return sum;
}
