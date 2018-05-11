#include "HeapAPI.h"
#include "integer.h"
/**
 * Internal functions to search for the max element between the data stored at index i
 * and the left child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxLeft(Heap *heap,size_t i); 

/**
 * Internal functions to search for the max element between the data stored at index current
 * and the right child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxRight(Heap *heap,size_t curr, size_t i); 

/**************************************************************************************************************************/

Heap *createHeap(size_t initialSize, void (*destroyDataFP)(void *data),int (*compareFP)(const void *first, const void *second)){
    Heap *heap;
    if(!(heap = malloc(sizeof(Heap)))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    if(!(heap->heapArray = malloc(sizeof(Node)*initialSize))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    heap->type = MIN_HEAP;
    heap->currentSize = 0;
    heap->maxSize = initialSize;
    heap->destroyData = destroyDataFP;
    heap->compare = compareFP;
    return heap;
}

Node *createHeapNode(void *data){
    Node* newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    return newNode;
}

void insertHeapNode(Heap *heap, void *data){
    int coolPlace = currentSize(heap);
    
    Node* newNode = createHeapNode(data);
    heap->heapArray[coolPlace] = newNode;
    coolPlace++;
    int i = 0;
    int k = 0;
    int temp = 0;
    heap->currentSize = coolPlace;
    if(coolPlace > 1){
        for(i = 0; i < heap->currentSize; i++){
	    for(k = 0; k < (heap->currentSize - 1); k++){
		if(heap->compare(heap->heapArray[i], heap->heapArray[k])== -1){
		    temp = *(int*)heap->heapArray[i]->data;
		    *(int*)heap->heapArray[i]->data = *(int*)heap->heapArray[k]->data;
		    *(int*)heap->heapArray[k]->data = temp;
		}
	    }
	}
    }    
}

void deleteRoot(Heap *heap) {
    Node *temp;
    if(heap->currentSize>0) {
        temp = heap->heapArray[0];
        (heap->currentSize)--;
        heap->heapArray[0] = heap->heapArray[heap->currentSize];
        heap->destroyData(temp);
        heapify(heap, 0) ;
    } else {
        fprintf(stderr,"Heap is empty.\n") ;
	}
}

void deleteHeap(Heap *heap){
    size_t i;
    i = heap->currentSize;
    while(i>0){
        deleteRoot(heap);
        i--;
    }
    free(heap->heapArray);
    free(heap);
}

void* getRoot(Heap *heap){
    return heap->heapArray[0]->data;
}

void heapify(Heap *heap, size_t i){
    int j = 0; 
    int k = 0;
    int temp = 0;
    for(j = 0; j < i; j++){
	for(k = 0; k < (i-1); k++){
	    if(heap->compare(heap->heapArray[j], heap->heapArray[k])==1){
	         temp = *(int*)heap->heapArray[k]->data;
		 *(int*)heap->heapArray[k]->data = *(int*)heap->heapArray[j]->data;
		 *(int*)heap->heapArray[j]->data = temp;
	    }
	}
    }
}


size_t findMaxLeft(Heap *heap,size_t i){
    size_t  leftIdx = getLeftChildIndex( i );
    if( leftIdx < heap->currentSize && heap->compare(heap->heapArray[leftIdx]->data,heap->heapArray[i]->data) > 0){
        return leftIdx;
    }
    return i;
}

size_t findMaxRight(Heap *heap,size_t curr, size_t i){
    size_t rightIdx = getRightChildIndex( curr );
    if( rightIdx < heap->currentSize && heap->compare(heap->heapArray[rightIdx]->data,heap->heapArray[i]->data) > 0){
      return rightIdx;
    }
    return i;
}


size_t getLeftChildIndex(size_t index)
{
    size_t leftChild = (2*index)+1;
    return leftChild;
}

size_t getRightChildIndex(size_t index)
{
    size_t rightChild = (2*index)+2;

    return rightChild;
}

size_t getParentIndex(size_t index)
{
    size_t parent = (index - 1)/2;
    return parent;
    
}

size_t currentSize(Heap* heap)
{
    return heap->currentSize;
}

void* search(Heap* heap, void* data)
{       
    for(size_t i =0; i < currentSize(heap);i++) 
    {
        if( heap->compare(data,heap->heapArray[i]->data) == 0)
            return heap->heapArray[i]->data;
    }
    return NULL;
}


void printHeap(Heap* heap, void (*printFunc)(void*) )
{
    int i = 0;
    for(i = 0; i < currentSize(heap); i++){
	printFunc(heap->heapArray[i]->data);
    }
}
