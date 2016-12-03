template <class Q> class Queue{
    public:
        Queue(){
            head=tail=NULL;
        }
        ~Queue(){
            for(Node<Q> *ptr;!isQueueEmpty();ptr=ptr->next){
                ptr=head->next;
//                std::cout<<"Deleting "<<head->data<<std::endl;
                delete head;
                head=ptr;
            }
        }
        void enqueue(Q idata){
            if(isQueueEmpty()){
                head=tail=new Node<Q>(idata,0);
                return;
            }
            tail->next=new Node<Q>(idata,0);
            tail=tail->next;
        }
        void dequeue(){
            if(isQueueEmpty())
                return;
            if(head==tail){
                delete head;
                head=tail=NULL;
            } else {
                Node<Q> *ptr=head->next;
                delete head;
                head=ptr;
            }
        }
        Q getTop(){
            return head->data;
        }
        bool isQueueEmpty(){
            return head==NULL;
        }
        void printQueue(){
            for(Node<Q> *ptr=head;ptr!=NULL;ptr=ptr->next)
                std::cout<<ptr->data<<" ";
            std::cout<<"\n";
        }
        Node<Q> *head,*tail;
};
