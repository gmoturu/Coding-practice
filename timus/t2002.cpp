#include<iostream>
using namespace std;
int calculateHash(std::string,int);

class Node
{
    public:
	Node()
	{
	    next=NULL;
	}
	Node(std::string iusername,std::string ipassword,Node *inext)
	{
	    username=iusername;
	    password=ipassword;
	    status=0;
	    next=inext;
	}
	std::string username;
	std::string password;
	bool status;
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
//		std::cout<<"Deleting "<<head->username<<std::endl;
		delete head;
		head=ptr;
	    }
	}
	void registerUser(std::string iusername,std::string ipassword)
	{
	    std::cout<<"success: new user added\n";
	    head=new Node(iusername,ipassword,head);
	}
	bool isInList(std::string iusername)
	{
	    for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
		if(ptr->username.compare(iusername)==0)
		    return 1;
	    return 0;
	}
	void loginUser(std::string iusername,std::string ipassword)
	{
	    Node *ptr;
	    for(ptr=head;ptr->username.compare(iusername)!=0;ptr=ptr->next);
	    if(ptr->password.compare(ipassword)==0 && ptr->status==0)
	    {
		std::cout<<"success: user logged in\n";
		ptr->status=1;
	    }
	    else if(ptr->password.compare(ipassword)==0 && ptr->status==1)
		std::cout<<"fail: already logged in\n";
	    else if(ptr->password.compare(ipassword)!=0)
		std::cout<<"fail: incorrect password\n";
	}
	void logoutUser(std::string iusername)
	{
	    Node *ptr;
	    for(ptr=head;ptr->username.compare(iusername)!=0;ptr=ptr->next);
	    if(ptr->status==0)
		std::cout<<"fail: already logged out\n";
	    else
	    {
		std::cout<<"success: user logged out\n";
		ptr->status=0;
	    }
	}
    private:
	Node *head;
};

int main()
{
    int N;
    std::cin>>N;

    List *lst[N];
    for(int i=0;i<N;i++)
	lst[i]=NULL;

    std::string opr[N],usr[N],pwd[N];
    for(int i=0;i<N;i++)
    {
	std::cin>>opr[i];
	if(opr[i].compare("logout")==0)
	    std::cin>>usr[i];
	else
	    std::cin>>usr[i]>>pwd[i];
    }

    for(int i=0;i<N;i++)
    {
	int hashval=calculateHash(usr[i],N);
	if(lst[hashval]==NULL)
	    lst[hashval]=new List;
	if(opr[i].compare("register")==0)
	{
	    if(lst[hashval]->isInList(usr[i]))
		std::cout<<"fail: user already exists\n";
	    else
		lst[hashval]->registerUser(usr[i],pwd[i]);
	}
	if(opr[i].compare("login")==0)
	{
	    if(lst[hashval]->isInList(usr[i]))
		lst[hashval]->loginUser(usr[i],pwd[i]);
	    else
		std::cout<<"fail: no such user\n";
	}
	if(opr[i].compare("logout")==0)
	{
	    if(lst[hashval]->isInList(usr[i]))
		lst[hashval]->logoutUser(usr[i]);
	    else
		std::cout<<"fail: no such user\n";
	}
    }

    for(int i=0;i<N;i++)
	if(lst[i]!=NULL)
	    delete lst[i];

    return 0;
}

int calculateHash(std::string iusername,int N)
{
    int hashval=0;
    for(const char *ptr=iusername.c_str();*ptr;ptr++)
	hashval+=*ptr;
    hashval=hashval%N;
    return hashval;
}
