#include<iostream>
#define N 6
using namespace std;

class Node
{
    public:
	Node()
	{
	    next=NULL;
	}
	Node(string iname,int iprice)
	{
	    name=iname;
	    price=iprice;
	    count=1;
	    next=NULL;
	}
	string name;
	int price;
	int count;
	Node *next;
};

class List
{
    public:
	List()
	{
	    head=tail=NULL;
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
	void addToTail(string iname,int iprice)
	{
	    if(tail==NULL)
			head=tail=new Node(iname,iprice);
	    else
	    {
			tail->next=new Node(iname,iprice);
			tail=tail->next;
	    }
	}
	void addOrUpdate(string iname,int iprice)
	{
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
	    {
			if(ptr->name.compare(iname)==0)
			{
			    ptr->count++;
		    	ptr->price > iprice ? ptr->price=iprice:iprice;
			    return;
			}
	    }
	    addToTail(iname,iprice);
	}
	void displayCheapnBest()
	{
	    Node *best=head;
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
			if((ptr->count > best->count) || (ptr->count == best->count && ptr->price < best->price))
		    	best=ptr;
	    std::cout<<best->name<<std::endl;
	}
    private:
	Node *head,*tail;
};

int main()
{
    List phone_list;
    string fname,phone;
    int price;

    for(int i=0;i<N;i++)
    {
		cin>>fname>>phone>>price;	
		phone_list.addOrUpdate(phone,price);
    }
    phone_list.displayCheapnBest();
    return 0;
}
