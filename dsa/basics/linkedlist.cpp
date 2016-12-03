#include<iostream>
using namespace std;
typedef int Item;

class Node
{
  public:
    Item data;
    Node *next;
    Node();
    Node(const Item & item,Node *n=NULL);
};

class List
{
  private:
    Node *first;
    int size;
  public:
    List();
    bool isempty();
    void insert(Item item,int pos);
//    void erase(int pos);
    void display();
    ~List();
};

Node::Node()
{
  next=NULL;
}
Node::Node(const Item & item,Node *n)
{
  data=item;
  next=n;
}

List::List()
{
  first=NULL;
  size=0;
}
bool List::isempty()
{
  return (size==0);
}
void List::insert(Item item,int pos)
{
  if(pos<0 || pos>size)
  {
    cout<<"insert error"<<endl;
    return;
  }
  Node *temp=new Node(item);
  if(pos==0)
  {
    temp->next=first;
    first->temp;
  }
  else
  {
    Node *ptr=first;
    int p=0;
    while(p!=pos-1)
    {
      ptr=ptr->next;
      p++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
  }
  size++;
}
void List::display()
{
  Node *ptr=first;
  while(ptr)
  {
    cout<<ptr->data<<endl;
    ptr++;
  }
  cout<<endl;
}
int main()
{
  List l;
  l.display();
  for(int i=0;i<2;i++)
    l.insert(i,i);
  l.display();
  return 0;
}
