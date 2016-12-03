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
        void deleteList(){
            ~List();
        }
        bool isListEmpty(){
            return head==NULL;
        }
        void addToHead(L idata,int iweight=1){
            if(isListEmpty()){
                head=tail=new Node<L>(idata,iweight);
            } else {
                head=new Node<L>(idata,iweight,head);
            }
        }
        void addToTail(L idata,int iweight=1){
            if(isListEmpty()){
                head=tail=new Node<L>(idata,iweight);
                return;
            }
            tail->next=new Node<L>(idata,iweight);
            tail=tail->next;
        }
        void printDataOnly(){
            if(!isListEmpty()){
                for(Node<L> *ptr=head;ptr!=NULL;ptr=ptr->next)
                    std::cout<<ptr->data<<" ";
                NWLN;
            }
        }
        void mergeList(Node<L> *hptr,Node<L> *tptr){
            if(hptr!=NULL){
                tail->next=hptr;
                tail=tptr;
            }
        }
        void printList(){
            for(Node<L> *ptr=head;ptr!=NULL;ptr=ptr->next)
                std::cout<<ptr->data<<","<<ptr->weight<<" ";
            std::cout<<"\n";
        }
        Node<L> *head,*tail;
};
