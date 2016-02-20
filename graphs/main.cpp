#include"graph.h"
void printSearch(SearchGraph *);
int main(){
    Graph<char> gr;
    int edges,weight;
    char s_vertex,e_vertex;
    SearchGraph xfs[V];

    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>s_vertex>>e_vertex;
        gr.addEdge(s_vertex,e_vertex);
        gr.addEdge(e_vertex,s_vertex);
    }
    gr.printGraph();

    cin>>s_vertex;
    gr.depthFS(xfs,s_vertex);
    printSearch(xfs);

    cin>>s_vertex;
    gr.depthFS_Loop(xfs,s_vertex);
    printSearch(xfs);

    cin>>s_vertex;
    gr.breadthFS(xfs,s_vertex);
    printSearch(xfs);
/*
    gr.printGraph();
    Graph<char> rg,gp;
//    gr.reverseGraph(&rg);
//    rg.printGraph();
    gr.removeLoopsMultipleEdges(&gp);
//    gp.printGraph();
    char array[V];
    search_struct xfs[V];
    cin>>s_vertex;
    gr.breadthFS(s_vertex,xfs);
    for(int i=0;i<V;i++)
        cout<<xfs[i].vertex<<" ";
    cout<<"\n";
    gr.depthFS(s_vertex,array);
    for(int i=0;i<V;i++)
        cout<<array[i]<<" ";
    cout<<"\n";
*/
    return 0;
}

void printSearch(SearchGraph *xfs){
    for(int i=0;i<V;i++)
        if(xfs[i].vertex)
            std::cout<<xfs[i].vertex<<" "<<xfs[i].parent<<" "<<xfs[i].distance<<std::endl;
}
