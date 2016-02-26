// class definition of a node
#include"headers.h"
#define PARENT(i) (i-1)/2
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
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
struct BinaryHeap{
    char vertex;
    char parent;
    int distance;
};

void MinHeapify(BinaryHeap *arr,int heap_size,int i,int *heap_map){
    int l=LEFT(i);
    int r=RIGHT(i);
    int small=i;
    (l<heap_size && arr[l].distance<arr[i].distance)?small=l:small;
    (r<heap_size && arr[r].distance<arr[small].distance)?small=r:small;
    if(small!=i){
        BinaryHeap tmp;
        tmp=arr[i];
        arr[i]=arr[small];
        arr[small]=tmp;
        SWAP(heap_map[arr[i].vertex-O],heap_map[arr[small].vertex-O]);
        MinHeapify(arr,heap_size,small,heap_map);
    }
}
void BuildMinHeap(BinaryHeap *arr,int heap_size,int *heap_map){
    for(int i=heap_size/2;i>=0;i--)
        MinHeapify(arr,heap_size,i,heap_map);
}
void HeapExtractMin(BinaryHeap *arr,int *heap_size,int *heap_map){
    arr[0]=arr[*heap_size-1];
    heap_map[arr[*heap_size-1].vertex]=0;
    (*heap_size)--;
    MinHeapify(arr,*heap_size,0,heap_map);
}
void HeapDecreaseKey(BinaryHeap *arr,int index,int *heap_map){
    /*
    for(int j=PARENT(i);i>0 && arr[j].distance>arr[i].distance;i=j,j=PARENT(j)){
        std::cout<<i<<" "<<j<<std::endl;
        BinaryHeap tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        SWAP(heap_map[arr[i].vertex-O],heap_map[arr[j].vertex-O]);
    }
    */
}

void MaxHeapify(BinaryHeap *arr,int heap_size,int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int large=i;
    (l<heap_size && arr[l].distance>arr[i].distance)?large=l:large;
    (r<heap_size && arr[r].distance>arr[large].distance)?large=r:large;
    if(large!=i){
        BinaryHeap tmp=arr[i];
        arr[i]=arr[large];
        arr[large]=tmp;
        MaxHeapify(arr,heap_size,large);
    }
}
void BuildMaxHeap(BinaryHeap *arr,int heap_size){
    for(int i=heap_size/2;i>=0;i--)
        MaxHeapify(arr,heap_size,i);
}
void SortEdges(BinaryHeap *arr,int heap_size){
    BuildMaxHeap(arr,heap_size);
    while(heap_size>0){
        BinaryHeap tmp=arr[0];
        arr[0]=arr[heap_size-1];
        arr[heap_size-1]=tmp;
        heap_size--;
        MaxHeapify(arr,heap_size,0);
    }
}
