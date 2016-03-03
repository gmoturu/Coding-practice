#include"list.h"
#include"graph_matrix.h"
int main(){
	Graph_Matrix gr;
	int edges,weight;
	char s_vertex,e_vertex;
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>s_vertex>>e_vertex>>weight;
		gr.addEdge(s_vertex,e_vertex,weight);
	}
	gr.printGraph();
	return 0;
}
