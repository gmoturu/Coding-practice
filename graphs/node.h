// class definition of a node
#include"headers.h"
#define PARENT(i) (i-1)/2
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
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

void MinHeapify(BinaryHeap *arr,int heap_size,int i){
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
        MinHeapify(arr,heap_size,small);
    }
}
void BuildMinHeap(BinaryHeap *arr,int heap_size){
    for(int i=heap_size/2;i>=0;i--)
        MinHeapify(arr,heap_size,i);
}
void HeapExtractMin(BinaryHeap *arr,int *heap_size){
    arr[0]=arr[*heap_size-1];
    (*heap_size)--;
    MinHeapify(arr,*heap_size,0);
}
void HeapDecreaseKey(BinaryHeap *arr,int i){
    while(i>=0 && arr[i].distance < arr[PARENT(i)].distance){
        BinaryHeap tmp=arr[i];
        arr[i]=arr[PARENT(i)];
        arr[PARENT(i)]=tmp;
        i=PARENT(i);
    }
}
