#include"list.h"
#include"queue.h"
#include"stack.h"
template <class G> class Graph{
    public:
        void prims_mst(SearchGraph *xfs,G s_vertex){
            bool visited[V]={0};
            int heap_map[V];
            BinaryHeap heap_array[V];
            for(int i=0;i<V;i++){
                xfs[i].vertex=0;
                heap_array[i].vertex=i+O;
                xfs[i].distance=heap_array[i].distance=INT_MAX;
                xfs[i].parent=heap_array[i].parent='-';
                heap_map[i]=i;
            }
            heap_array[s_vertex-O].vertex=s_vertex;
            heap_array[s_vertex-O].distance=0;
            int heap_size=V,i=0;
            for(BuildMinHeap(heap_array,heap_size,heap_map);heap_array[0].distance!=INT_MAX;HeapExtractMin(heap_array,&heap_size,heap_map),BuildMinHeap(heap_array,heap_size,heap_map)){
                i=heap_array[0].vertex-O;

                xfs[i].vertex=heap_array[0].vertex;
                xfs[i].parent=heap_array[0].parent;
                xfs[i].distance=heap_array[0].distance;
                visited[i]=1;

                for(Node<G> *ptr=lst[i].head;ptr!=NULL;ptr=ptr->next){
                    if(!visited[ptr->data-O] && heap_array[heap_map[ptr->data-O]].distance>ptr->weight){
                        heap_array[heap_map[ptr->data-O]].vertex=ptr->data;
                        heap_array[heap_map[ptr->data-O]].parent=heap_array[0].vertex;
                        heap_array[heap_map[ptr->data-O]].distance=ptr->weight;
                    }
                }
            }
        }
        void stronglyConnected(Graph<G> *rg,G s_vertex,List<G> *scc){
            List<G> top;
            bool visited[V];
            for(int i=0;i<V;i++)
                visited[i]=0;
            int i=0;
            topologicalSort(s_vertex,&top);
            for(Node<G> *ptr=top.head;ptr!=NULL;ptr=ptr->next){
                if(!visited[ptr->data-O]){
                    SearchGraph xfs[V];
                    rg->depthFS_Loop(xfs,ptr->data,visited);
                    for(int j=0;j<V;j++)
                        if(xfs[j].vertex!=0)
                            (scc+i)->addToTail(xfs[j].vertex);
                    i++;
                }
            }
        }
        void topologicalSort(G s_vertex,List<G> *top){
            bool visited[V];
            for(int i=0;i<V;i++)
                visited[i]=0;
            topoSort(s_vertex,top,visited);
            for(int i=0;i<V;i++)
                if(!visited[i] && !lst[i].isListEmpty())
                    topoSort(i+O,top,visited);
        }
        void topoSort(G s_vertex,List<G> *top,bool *visited){
            visited[s_vertex-O]=1;
            for(Node<G> *ptr=lst[s_vertex-O].head;ptr!=NULL;ptr=ptr->next){
                if(!visited[ptr->data-O]){
                    visited[ptr->data-O]=1;
                    topoSort(ptr->data,top,visited);
                }
            }
            (*top).addToHead(s_vertex);
        }
        void depthFS_Loop(SearchGraph *xfs,G s_vertex,bool *visited){
//            bool visited[V];
            for(int i=0;i<V;i++){
                xfs[i].vertex=xfs[i].distance=0;
                xfs[i].parent='-';
            }
            xfs[0].vertex=s_vertex;
            visited[s_vertex-O]=1;
            Stack<Node<G> *> nds;
            Stack<G> stk;
            Stack<int> dst;
            nds.push(lst[s_vertex-O].head);
            stk.push(s_vertex);
            dst.push(0);
            for(int i=0;!nds.isStackEmpty();){
                Node<G> *ptr=nds.getTop();
                for(;ptr!=NULL && visited[ptr->data-O];ptr=ptr->next);
                if(ptr){
                    nds.pop();
                    nds.push(ptr);
                    visited[ptr->data-O]=1;
                    i++;
                    xfs[i].vertex=ptr->data;
                    xfs[i].parent=stk.getTop();
                    xfs[i].distance=dst.getTop()+1;
                    nds.push(lst[ptr->data-O].head);
                    stk.push(ptr->data);
                    dst.push(xfs[i].distance);
                } else {
                    nds.pop();
                    stk.pop();
                    dst.pop();
                }
            }
        }
        void breadthFS(SearchGraph *xfs,G s_vertex){
            bool visited[V];
            for(int i=0;i<V;i++){
                visited[i]=xfs[i].vertex=xfs[i].distance=0;
                xfs[i].parent='-';
            }
            Queue<G> que;
            que.enqueue(s_vertex);
            xfs[0].vertex=s_vertex;
            visited[s_vertex-O]=1;
            for(int i=0,j=0;!que.isQueueEmpty();j++){
                s_vertex=que.getTop();
                for(Node<G> *ptr=lst[s_vertex-O].head;ptr!=NULL;ptr=ptr->next){
                    if(!visited[ptr->data-O]){
                        visited[ptr->data-O]=1;
                        que.enqueue(ptr->data);
                        i++;
                        xfs[i].vertex=ptr->data;
                        xfs[i].parent=s_vertex;
                        xfs[i].distance=xfs[j].distance+1;
                    }
                }
                que.dequeue();
            }
        }
        void depthFS(SearchGraph *xfs,G s_vertex){
            bool visited[V];
            for(int i=0;i<V;i++){
                visited[i]=xfs[i].vertex=xfs[i].distance=0;
                xfs[i].parent='-';
            }
            xfs[0].vertex=s_vertex;
            visited[s_vertex-O]=1;
            int i=0;
            dfs(s_vertex,visited,xfs,&i,0);
        }
        void dfs(G s_vertex,bool *visited,SearchGraph *xfs,int *i,int dist){
            for(Node<G> *ptr=lst[s_vertex-O].head;ptr!=NULL;ptr=ptr->next){
                if(!visited[ptr->data-O]){
                    *i=*i+1;
                    visited[ptr->data-O]=1;
                    xfs[*i].vertex=ptr->data;
                    xfs[*i].parent=s_vertex;
                    xfs[*i].distance=dist+1;
                    dfs(ptr->data,visited,xfs,i,xfs[*i].distance);
                }
            }
        }
        void addEdge(G s_vertex,G e_vertex,int iweight=1){
            lst[s_vertex-O].addToTail(e_vertex,iweight);
        }
        void printGraph(){
            for(int i=0;i<V;i++){
                if(!lst[i].isListEmpty()){
                    std::cout<<(char)(i+O)<<": ";
                    lst[i].printList();
                }
            }
        }
        void reverseGraph(Graph<G> *rg){
            for(int i=0;i<V;i++)
                for(Node<G> *ptr=lst[i].head;ptr!=NULL;ptr=ptr->next)
                    rg->lst[ptr->data-O].addToTail(i+O,ptr->weight);
        }
        void removeLoopsMultipleEdges(Graph<G> *gp){
            for(int i=0;i<V;i++){
                bool tmp_array[V];
                for(int i=0;i<V;i++)
                    tmp_array[i]=0;
                for(Node<G> *ptr=lst[i].head;ptr!=NULL;ptr=ptr->next){
                    if((ptr->data-O)!=i && !tmp_array[i])
                        gp->lst[i].addToTail(ptr->data,ptr->weight);
                    tmp_array[ptr->data-O]=1;
                }
            }
        }
        List<G> lst[V];
};
