#include<iostream>
#define ALP 26
#define ASC 97
#define HG 3
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
	    str=istr;;
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
	void displayList()
	{
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
		std::cout<<ptr->str<<std::endl;
	}
    private:
	Node *head;
};

int main()
{
    List *lst[ALP];
    for(int i=0;i<ALP;i++)
	lst[i]=NULL;

    std::string str;
    int N;
    std::cin>>N;

    for(int i=0;i<N;i++)
    {
	std::cin>>str;
	if(lst[str[0]-ASC]==NULL)
	    lst[str[0]-ASC]=new List;
	lst[str[0]-ASC]->push(str);
    }

    char c;
    std::cin>>c;
    if(lst[c-ASC]!=NULL)
	lst[c-ASC]->displayList();

    for(int i=0;i<ALP;i++)
	if(lst[i]!=NULL)
	    delete lst[i];

    return 0;
}
