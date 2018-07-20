#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicString.h"




/*****STATIC*****/


/***FIX ME***/
static void _____insert_min_heap(Heap heap, AnyData d)
{
    CompareData comparator = heap->compareData;
    int index = heap->size;
    int memSize = heap->size + 1;
    heap->heapArray = realloc(heap->heapArray, memSize*sizeof(AnyData));

}


/***END STATIC***/



/***CONSTRUCTORS***/

static String _____set_heap_type(HeapType heapType)
{
    String type = NULL;
    if(type == MAX){
        type = stringcopy("Max");
    }
    else{
        type = stringcopy("Min");
    }
    return type;
}

HeapNode new_heap_node(AnyData data)
{
    if(data == NULL)return NULL;
    new_object(HeapNode, newNode, 1);
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Heap new_default_heap(PrintFunc p, DeleteFunc d, CompareFunc c)
{
    if(p == NULL || d == NULL || c== NULL)return NULL;
    new_object(Heap, heap, 1);
    heap->capacity = _____heapSizes[5];
    heap->size = 0;
    heap->height = 0;
    heap->heapType = MAX;
    heap->type = _____set_heap_type(heap->heapType);
    heap->root = NULL;

    heap->heapArray = NULL;
    heap->printData = p;
    heap->deleteData = d;
    heap->compareData = c;

    return heap;

}

Heap new_heap(HeapType type, unsigned int size, PrintFunc p, DeleteFunc d, CompareFunc c)
{
    if(type != MAX && type != MIN){
        return NULL;
    }
    if(size <= 0){
        return NULL;
    }
    if(p == NULL || d == NULL || c== NULL)return NULL;

    
    
    new_object(Heap, heap, 1);
   
    int index = 0;
    if(size >= 10){
        index = 9;
    }else{
        index = size-1;
    }
    heap->capacity = _____heapSizes[index];
    heap->size = 0;
    heap->height = 0;

    heap->heapType = type;
    heap->type = _____set_heap_type(type);


    heap->heapArray = NULL;
    heap->root = NULL;

    heap->printData = p;
    heap->deleteData = d;
    heap->compareData = c;

    return heap;
}

/***END CONSTRUCTORS***/


/***ACCESSORS***/

AnyData get_heap_array(Heap heap){
    
    if(heap == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->heapArray == NULL)return NULL;

    return (void*)heap->heapArray;
}

unsigned long get_heap_capacity(Heap heap)
{
    if(heap == NULL)return -1;
    return heap->capacity;
}

unsigned long get_heap_size(Heap heap)
{
    if(heap == NULL)return -1;
    return heap->size;
}


unsigned long get_heap_height(Heap heap)
{
    if(heap == NULL)return -1;
    return heap->height;
}

AnyData get_heap_data(Heap heap, AnyData d)
{
    if(heap == NULL)return NULL;
    if(d == NULL)return NULL;
    if(heap->size <= 0)return NULL;
    if(contains_data_heap(heap, d)==false)return NULL;
    CompareFunc comparator = heap->compareData;
    forall(heap->size){
        if(comparator(heap->array[x], d)==0){
            return heap->array[x];
        }
    }
}

AnyData get_min_data(Heap heap)
{
    if(heap == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    //if
    if(heap->type == MIN){
        return heap->root->data;
    }//end if

    //else
    else{
        CompareFunc comparator = heap->compareData;
        AnyData* array = heap->heapArray;
        int size = sizeof(array)/sizeof(array[0]);
        qsort(array, heap->size, size, comparator);
        return array[0];

    }//end else

}

AnyData get_max_data(Heap heap)
{
    if(heap == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    //if
    if(heap->type == MAX){
        return heap->root->data;
    }//end if

    //else
    else{
        CompareFunc comparator = heap->compareData;
        AnyData* array = heap->heapArray;
        int size = sizeof(array)/sizeof(array[0]);
        qsort(array, heap->size, size, comparator);
        return array[size-1];

    }//end else

}

AnyData get_parent_data(Heap heap, AnyData d)
{
    if(heap == NULL)return NULL;
    if(d == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    if(contains_data_heap(heap, d)==false)return NULL;


    int index = -1;
    CompareFunc comparator = heap->comapreData;
    forall(heap->size){
        if(comparator(heap->heapArray[x], d)==0){
            index = x;
        }
    }

    if(x == 0){
        NULL;
    }

    if((index%2)==0){
        index = (index/2) -1;
        if(index < 0)return NULL;
        return heap->heapArray[index];
    }else{
        index = index/2;
        if(index < 0)return NULL;
        return heap->heapArray[index];
    }
}

AnyData get_left_child_data(Heap heap, AnyData d)
{
    if(heap == NULL)return NULL;
    if(d == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    if(contains_data_heap(heap, d)==false)return NULL;
    
    int index = -1;
    CompareFunc comparator = heap->compareData;
    forall(heap->size){
        if(comparator(heap->heapArray[x], d)==0){
            index = x;
        }
    }
    index = (2*index)+1;
    if(index >= heap->size){
        return NULL;
    }
    return heap->heapArray[index];

} 

AnyData get_right_child_data(Heap heap, AnyData d)
{
    if(heap == NULL)return NULL;
    if(d == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    if(contains_data_heap(heap, d)==false)return NULL;
    
    int index = -1;
    CompareFunc comparator = heap->compareData;
    forall(heap->size){
        if(comparator(heap->heapArray[x], d)==0){
            index = x;
        }
    }
    index = index*2 + 2;
    if(index >= heap->size){
        return NULL;
    }
    return heap->heapArray[index];    
}

String get_heap_type(Heap heap)
{
    if(heap == NULL)return NULL;
    if(heap->type == NULL)return NULL;
    return heap->type;
}

/**END ACCESSORS***/


/****SETTERS***/

HeapError insert_data_heap(Heap heap, AnyData d)
{
    if(heap == NULL)return DNE_HEAP;
    if(d == NULL)return DNE_HEAP;
    if(heap->size == heap->capacity)return OOM_HEAP;

    //if
    if(heap->root == NULL){
        heap->root = new_heap_node(d);
        heap->size++;
        heap->heapArray = calloc(heap->size, sizeof(AnyData));
        int index = heap->size - 1;
        heap->heapArray[index] = d;
    }//endif
    

    //FIX ME
    //else
    else{
        //create two static functions, one for a max heap and one for a min heap
        if(heap->heapType == MIN){
            //call min add
        }else{
            //call max add
        }
    }
}
















































/****VALIDATORS***/



bool contains_data_heap(Heap heap, AnyData d)
{
    if(heap == NULL)return false;
    if(d == NULL)return false;
    if(heap->size <= 0)return false;
    CompareFunc comparator = heap->compareData;
    forall(heap->size){
        if(comparator(heap->heapArray[x], d)==0){
            return true;
        }
    }
    return false;
}
/***END VALIDATORS***/