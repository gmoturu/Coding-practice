#include"graph.h"
#define SZ 10
void printSearch(SearchGraph *);
int main(){
    Graph<char> gr,rg,gp;
    int edges,weight;
    char s_vertex,e_vertex;
    SearchGraph xfs[V];
    bool visited[V]={0};

    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>s_vertex>>e_vertex>>weight;
        gr.addEdge(s_vertex,e_vertex,weight);
//        gr.addEdge(e_vertex,s_vertex,weight);
    }
    gr.printGraph();

    cin>>s_vertex;
    gr.djikstra(xfs,s_vertex);
    printSearch(xfs);

    /*
    gr.kruskals_mst(xfs,s_vertex,edges);
    printSearch(xfs);
    gr.prims_mst(xfs,s_vertex);
    printSearch(xfs);
    cin>>s_vertex;
    gr.prims_mst(xfs,s_vertex);
    printSearch(xfs);

    gr.reverseGraph(&rg);

    gr.printGraph();
    rg.printGraph();

    cin>>s_vertex;
    List<char> top;
    gr.topologicalSort(s_vertex,&top);
    top.printDataOnly();

    cin>>s_vertex;
    gr.depthFS(xfs,s_vertex);
    printSearch(xfs);

    cin>>s_vertex;
    gr.depthFS_Loop(xfs,s_vertex,visited);
    printSearch(xfs);

    cin>>s_vertex;
    gr.breadthFS(xfs,s_vertex);
    printSearch(xfs);

    List<char> scc[V];
    cin>>s_vertex;
    gr.stronglyConnected(&rg,s_vertex,scc);
    for(int i=0;i<V;i++)
        if(!scc[i].isListEmpty())
            scc[i].printDataOnly();

    gr.removeLoopsMultipleEdges(&gp);
    gp.printGraph();
    */

    return 0;
}

void printSearch(SearchGraph *xfs){
    for(int i=0;i<V;i++)
        if(xfs[i].vertex)
            std::cout<<xfs[i].vertex<<" "<<xfs[i].parent<<" "<<xfs[i].distance<<std::endl;
}
