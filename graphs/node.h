// class definition of a node
#include"headers.h"
template <class N> class Node{
    public:
        Node(){
            next=NULL;
        }
        Node(N idata,int iweight,Node *inext=NULL){
            data=idata;
            weight=iweight;
            next=inext;
        }
        N data;
        int weight;
        Node *next;
};

class SearchGraph{
        public:
            char vertex;
            char parent;
            int distance;
};
