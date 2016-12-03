template <class S> class Stack{
    public:
        Stack(){
            head=NULL;
        }
        ~Stack(){
            for(Node<S> *ptr;!isStackEmpty();){
                ptr=head->next;
//                std::cout<<"Deleting "<<head->data<<std::endl;
                delete head;
                head=ptr;
            }
        }
        bool isStackEmpty(){
            return head==NULL;
        }
        void push(S idata){
            head=new Node<S>(idata,0,head);
        }
        void pop(){
            if(!isStackEmpty()){
                Node<S> *ptr=head->next;
                delete head;
                head=ptr;
            }
        }
        S getTop(){
            return head->data;
        }
        void printStack(){
            for(Node<S> *ptr=head;ptr!=NULL;ptr=ptr->next)
                std::cout<<ptr->data<<" ";
            std::cout<<"\n";
        }
        Node<S> *head;
};
