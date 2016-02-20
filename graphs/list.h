#include"node.h"
template <class L> class List{
    public:
        List(){
            head=tail=NULL;
        }
        ~List(){
            for(Node<L> *ptr;!isListEmpty();){
                ptr=head->next;
//                std::cout<<"Deleting "<<head->data<<std::endl;
                delete head;
                head=ptr;
            }
        }
        bool isListEmpty(){
            return head==NULL;
        }
        void addToTail(L idata,int iweight){
            if(isListEmpty()){
                head=tail=new Node<L>(idata,iweight);
                return;
            }
            tail->next=new Node<L>(idata,iweight);
            tail=tail->next;
        }
        void printList(){
            for(Node<L> *ptr=head;ptr!=NULL;ptr=ptr->next)
                std::cout<<ptr->data<<","<<ptr->weight<<" ";
            std::cout<<"\n";
        }
        Node<L> *head,*tail;
};
