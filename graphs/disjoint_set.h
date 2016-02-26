// inefficent disjoint set implementation
//#include"list.h"
template <class D> class Disjoint{
    public:
        Disjoint(){
            for(int i=0;i<V;i++){
                map[i].parent=(char)(i+O);
                map[i].vertex=(char)(i+O);
                lst[i].addToHead((char)(i+O));
            }

        }
        D findSet(D x){
            return map[x-O].parent;
        }
        void unionSet(D s_vertex,D e_vertex){
            lst[s_vertex-O].mergeList(lst[map[e_vertex-O].parent-O].head,lst[map[e_vertex-O].parent-O].tail);
            lst[map[e_vertex-O].parent-O].head=NULL;

            map[map[e_vertex-O].parent-O].parent=s_vertex;
            for(Node<D> *ptr=lst[s_vertex-O].head;ptr!=NULL;ptr=ptr->next)
                map[ptr->data-O].parent=s_vertex;

        }
        List<D> lst[V];
        BinaryHeap map[V];
};
