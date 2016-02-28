class Graph_Matrix{
    public:
        Graph_Matrix(){
            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                    matrix[i][j]=INT_MAX;
        }
        void printGraph(){
            for(int i=0;i<V;i++){
                std::cout<<(char)(i+O)<<": ";
                for(int j=0;j<V;j++){
                    if(matrix[i][j]!=INT_MAX)
                        std::cout<<(char)(j+O)<<","<<matrix[i][j]<<" ";
                }
                NWLN;
            }
        }
        void addEdges(char s_vertex,char e_vertex,int weight=1){
            matrix[s_vertex-O][e_vertex-O]=weight;
        }
        int matrix[V][V];
};
