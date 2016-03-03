#include<iostream>
#include<string>
using namespace std;

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

class List
{
    public:
        List()
        {
            head=tail=NULL;
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
        bool isListEmpty()
        {
            return head==NULL;
        }
        void displayList()
        {
            for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
                std::cout<<ptr->name<<std::endl;
        }
        void addToTail(string iname)
        {
            if(tail==NULL)
                head=tail=new Node(iname);
            else
            {
                tail->next=new Node(iname);
                tail=tail->next;
            }
        }
    private:
        Node *head,*tail;
};

int main()
{
	unsigned N;
	std::cin>>N;
	std::cin.ignore();

	List gryffindor,hufflepuff,slytherin,ravenclaw;

	string person,house;
	for(int i=1;i<=N;i++)
	{
		getline(cin,person);
		getline(cin,house);
		if(house.compare("Slytherin")==0)
			slytherin.addToTail(person);
		else if(house.compare("Hufflepuff")==0)
			hufflepuff.addToTail(person);
		else if(house.compare("Gryffindor")==0)
			gryffindor.addToTail(person);
		else if(house.compare("Ravenclaw")==0)
			ravenclaw.addToTail(person);
	}

	std::cout<<"Slytherin:"<<std::endl;
	slytherin.displayList();
	std::cout<<"\n";

	std::cout<<"Hufflepuff:"<<std::endl;
    hufflepuff.displayList();
    std::cout<<"\n";

	std::cout<<"Gryffindor:"<<std::endl;
    gryffindor.displayList();
    std::cout<<"\n";

	std::cout<<"Ravenclaw:"<<std::endl;
    ravenclaw.displayList();
    std::cout<<"\n";

	return 0;
}
