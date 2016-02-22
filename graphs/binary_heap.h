//#include"headers.h"
#define PARENT(i) (i-1)/2
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
void printHeapArray(int *arr,int heap_size){
    for(int i=0;i<heap_size;i++)
        std::cout<<arr[i]<<" ";
    NWLN;
}
void MinHeapify(int *arr,int heap_size,int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int small=i;
    (l<heap_size && arr[l]<arr[i])?small=l:small;
    (r<heap_size && arr[r]<arr[small])?small=r:small;
    if(small!=i){
        SWAP(arr[i],arr[small]);
        MinHeapify(arr,heap_size,small);
    }
}
void BuildMinHeap(int *arr,int heap_size){
    for(int i=heap_size/2;i>=0;i--)
        MinHeapify(arr,heap_size,i);
}
void HeapExtractMin(int *arr,int *heap_size){
    arr[0]=arr[*heap_size-1];
    (*heap_size)--;
    MinHeapify(arr,*heap_size,0);
}
void HeapDecreaseKey(int *arr,int index,int key){
//    if(arr[index]<key)
//        return;
    arr[index]=key;
    for(int j=PARENT(index);j>=0 && arr[j]>arr[index];index=j,j=PARENT(j))
        SWAP(arr[index],arr[j]);
}
void MinHeapInsert(int *arr,int *heap_size,int key){
    arr[*heap_size]=key;
    (*heap_size)++;
    HeapDecreaseKey(arr,*heap_size-1,key);
}
void MaxHeapify(int *arr,int heap_size,int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int large=i;
    (l<heap_size && arr[l]>arr[i])?large=l:large;
    (r<heap_size && arr[r]>arr[large])?large=r:large;
    if(large!=i){
        SWAP(arr[i],arr[large]);
        MaxHeapify(arr,heap_size,large);
    }
}
void BuildMaxHeap(int *arr,int heap_size){
    for(int i=heap_size/2;i>=0;i--)
        MaxHeapify(arr,heap_size,i);
}
void HeapExtractMax(int *arr,int *heap_size){
    arr[0]=arr[*heap_size-1];
    (*heap_size)--;
    MaxHeapify(arr,*heap_size,0);
}
void HeapIncreaseKey(int *arr,int index,int key){
//    if(arr[index]>key)
//        return;
    arr[index]=key;
    for(int j=PARENT(index);j>=0 && arr[j]<arr[index];index=j,j=PARENT(j))
        SWAP(arr[index],arr[j]);
}
void MaxHeapInsert(int *arr,int *heap_size,int key){
    arr[*heap_size]=key;
    (*heap_size)++;
    HeapIncreaseKey(arr,*heap_size-1,key);
}
