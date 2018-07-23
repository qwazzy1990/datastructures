#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DynamicString.h"
#include "Heap.h"


/*****META DATA***/
static unsigned long _____HEAP_SIZES[10] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
/****END META DATA****/

/*****STATIC*****/


static void _____insert_min_heap(Heap heap, AnyData d)
{
    CompareFunc comparator = heap->compareData;
    int index = heap->size;
    (heap->size)++;
    int memSize = heap->size;
    heap->heapArray = realloc(heap->heapArray, memSize*sizeof(AnyData));
    heap->heapArray[index] = d;
    qsort(heap->heapArray, heap->size, sizeof(void*), comparator);

}

static void _____insert_max_heap(Heap heap, AnyData d)
{
    CompareFunc comparator = heap->compareData;
    int index = heap->size;
    (heap->size)++;

    int memSize = heap->size;
    heap->heapArray = realloc(heap->heapArray, memSize*sizeof(AnyData));
    heap->heapArray[index] = d;
    qsort(heap->heapArray, heap->size, sizeof(void*), comparator);
    int endIndex = heap->size - 1;
    for(int i = 0; i < (heap->size)/2; i++){
        void* temp = heap->heapArray[i];
        heap->heapArray[i] = heap->heapArray[endIndex];
        heap->heapArray[endIndex] = temp;
        endIndex--;
    }

}
static String _____set_heap_type(HeapType heapType)
{
    String type = NULL;
    if(heapType == MAX){
        type = stringcopy("Max");
    }
    else{
        type = stringcopy("Min");
    }
    return type;
}



/***END STATIC***/



/***CONSTRUCTORS***/



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
    heap->capacity = _____HEAP_SIZES[5];
    heap->size = 0;
    heap->height = 0;
    heap->heapType = MAX;
    heap->type = _____set_heap_type(heap->heapType);


    heap->root = NULL;

    heap->heapArray = NULL;
    
    
    heap->printData = p;
    heap->deleteData = d;
    heap->compareData = c;

    /***FUNCTION POINTERS TO ACCESSORS**/
    heap->get_height = get_heap_height;
    heap->get_size = get_heap_size;
    heap->get_array = get_heap_array;
    heap->get_capacity = get_heap_capacity;
    heap->get_data = get_heap_data;
    heap->get_max = get_max_data;
    heap->get_min = get_min_data;
    heap->get_left_child = get_left_child_data;
    heap->get_right_child = get_right_child_data;
    heap->get_parent = get_parent_data;
    heap->get_type = get_heap_type;
    /**END**/

    /***FUNCTION POINTERS TO SETTERS***/
    heap->set_height = set_heap_height;
    heap->add = insert_data_heap;
    heap->resize = resize_heap;
    /**END**/

    /***FUNCTION POINTERS TO MUTATORS**/
    heap->print = print_heap;
    heap->to_string = heap_to_string;
    /**END**/

    /***FUNCTION POINTERS TO VALIDATORS***/
    heap->is_empty = is_empty_heap;
    heap->is_full = is_full_heap;
    heap->contains = contains_data_heap;
    /**END**/

    /***FUNCTION POINTERS TO DESTROYERS***/
    heap->destroy = destroy_heap_real;
    heap->destroy_data = destroy_data_heap;
    heap->destroy_left_child = destroy_left_child_data;
    heap->destroy_right_child = destroy_right_child_data;
    heap->destroy_parent = destroy_parent_data;
    heap->destroy_root = destroy_root_data_heap;
    /**END**/
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
    heap->capacity = _____HEAP_SIZES[index];
    heap->size = 0;
    heap->height = 0;

    heap->heapType = type;
    heap->type = _____set_heap_type(type);


    heap->heapArray = NULL;
    heap->root = NULL;

    heap->printData = p;
    heap->deleteData = d;
    heap->compareData = c;

     /***FUNCTION POINTERS TO ACCESSORS**/
    heap->get_height = get_heap_height;
    heap->get_size = get_heap_size;
    heap->get_array = get_heap_array;
    heap->get_capacity = get_heap_capacity;
    heap->get_data = get_heap_data;
    heap->get_max = get_max_data;
    heap->get_min = get_min_data;
    heap->get_left_child = get_left_child_data;
    heap->get_right_child = get_right_child_data;
    heap->get_parent = get_parent_data;
    heap->get_type = get_heap_type;
    /**END**/

    /***FUNCTION POINTERS TO SETTERS***/
    heap->set_height = set_heap_height;
    heap->add = insert_data_heap;
    heap->resize = resize_heap;
    /**END**/

    /***FUNCTION POINTERS TO MUTATORS**/
    heap->print = print_heap;
    heap->to_string = heap_to_string;
    /**END**/

    /***FUNCTION POINTERS TO VALIDATORS***/
    heap->is_empty = is_empty_heap;
    heap->is_full = is_full_heap;
    heap->contains = contains_data_heap;
    /**END**/

    /***FUNCTION POINTERS TO DESTROYERS***/
    heap->destroy = destroy_heap_real;
    heap->destroy_data = destroy_data_heap;
    heap->destroy_left_child = destroy_left_child_data;
    heap->destroy_right_child = destroy_right_child_data;
    heap->destroy_parent = destroy_parent_data;
    heap->destroy_root = destroy_root_data_heap;

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
        if(comparator(heap->heapArray[x], d)==0){
            return heap->heapArray[x];
        }
    }
    return NULL;
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
        qsort(array, heap->size, sizeof(array[0]), comparator);
        return array[0];

    }//end else

}

AnyData get_max_data(Heap heap)
{
    if(heap == NULL)return NULL;
    if(heap->size == 0)return NULL;
    if(heap->root == NULL)return NULL;
    //if
    if(heap->heapType == MAX){
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
    CompareFunc comparator = heap->compareData;
    forall(heap->size){
        if(comparator(heap->heapArray[x], d)==0){
            index = x;
        }
    }

    if(index <= 0){
       return NULL;
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
        set_heap_height(heap);
    }//endif
    

    //FIX ME
    //else
    else{
        //create two static functions, one for a max heap and one for a min heap
        if(heap->heapType == MIN){
            _____insert_min_heap(heap, d);
        }else{
            _____insert_max_heap(heap, d);

        }
    }
    heap->root->data = heap->heapArray[0];
    set_heap_height(heap);
    return OK_HEAP;
}


HeapError set_heap_height(Heap heap)
{
    if(heap == NULL)return DNE_HEAP;
    if(heap->size == 0){
        heap->height = 0;
    }
    else{
        int size = heap->size;
        int l = log(size)/log(2);
        heap->height = l;
    }
    return OK_HEAP;
}

HeapError resize_heap(Heap heap, int newSize)
{
    if(heap == NULL)return DNE_HEAP;
    if(heap->size <= 0)return FAIL_ADD_HEAP;
    unsigned long oldcapacity = heap->capacity;
    heap->capacity = _____HEAP_SIZES[newSize];
    if(heap->size > heap->capacity){
        heap->capacity = oldcapacity;
        return FAIL_ADD_HEAP;
    }else{
        return OK_HEAP;
    }
}
/*****END SETTERS*****/



/***MUTATORS AND PRINTERS****/

String heap_to_string(Heap heap)
{
    PrintFunc printer = heap->printData;
    if(printer == NULL)return NULL;
    String printString = calloc(1000, sizeof(char));
    if(printString == NULL)return NULL;
    int memSize = 1000;
    String temp = NULL;
    forall(heap->size){
        void* d = heap->heapArray[x];
        temp = printer(d);
        if(temp == NULL){
            clear(printString);
            clear(temp);
            return NULL;
        }
        memSize += (stringlen(temp) + 10);
        printString = realloc(printString, memSize*sizeof(char));
        if(printString == NULL){
            clear(printString);
            clear(temp);
            return NULL;
        }
        strncat(printString, temp, strlen(temp)+1);
        strcat(printString, "\n");
        clear(temp);
    }
    return printString;
}


String print_heap(Heap heap)
{
    if(heap == NULL)return NULL;
    if(heap->size <= 0)return NULL;
    if(heap->heapArray == NULL)return NULL;
    String printer = heap_to_string(heap);
    if(printer == NULL)return NULL;
    #ifdef DEBUGP
        printf("%s\n", printer);
    #endif
    return printer;
}

/***END MUTATORS AND PRINTERS**/




/***DESTROYERS***/


HeapError destroy_data_heap(Heap heap, AnyData d)
{
    if(heap == NULL)return DNE_HEAP;
    if(d == NULL)return DNE_HEAP;
    if(contains_data_heap(heap, d)==false)return DNF_HEAP;
    AnyData* array = NULL;
    int oldSize = heap->size;
    (heap->size)--;
    array = calloc(heap->size, sizeof(*array));
    CompareFunc comparator = heap->compareData;
    int count = 0;
    int index = -1;
    forall(oldSize){
        void* temp = heap->heapArray[x];
        if(comparator(temp, d) != 0){
            array[count] = heap->heapArray[x];
            count++;
        }
        else{
            index = x;
        }
    }
    void** temp = heap->heapArray;
    clear(temp[index]);
    clear(temp);
    heap->heapArray = array;
    heap->root->data = heap->heapArray[0];
    set_heap_height(heap);

    return OK_HEAP;
}


HeapError destroy_root_data_heap(Heap heap)
{
    if(heap == NULL)return DNE_HEAP;
    if(heap->size <= 0)return DNF_HEAP;
    if(heap->root == NULL)return DNE_HEAP;
    
    DeleteFunc destroyer = heap->deleteData;
    if(heap->size == 1){
        destroyer(heap->root->data);
        clear(heap->root);
        heap->size--;
        heap->height = 0;
        clear(heap->heapArray);
        return OK_HEAP;
    }
    else{
        //void* tempTwo = heap->heapArray[0];
        void** array = calloc(heap->size - 1, sizeof(*array));
        int index = -1;
        int count = 0;
        forall(heap->size){
            if(heap->heapArray[x] != heap->root->data){
                array[count] = heap->heapArray[x];
                count++;
            }else{
                index = x;
            }
        }
        clear(heap->root->data);
        heap->root->data = array[index];
        clear(heap->heapArray);
        heap->heapArray = array;   
    }
    (heap->size)--;

    set_heap_height(heap);
    return OK_HEAP;
}






HeapError destroy_heap_real(Heap* heap)
{
    if(heap == NULL)return DNE_HEAP;
    Heap temp = *heap;
    if(temp == NULL){
        return DNE_HEAP;
    }
    if((*heap)->height == 0){
        clear(temp);
        *heap = NULL;
        return OK_HEAP;
    }
    DeleteFunc destroyer = temp->deleteData;
    if(destroyer == NULL)return FAIL_DELETE_HEAP;
    forall(temp->size){
        void* td = temp->heapArray[x];
        destroyer(td);
    }
    clear(temp->heapArray);
    clear(temp->type);
    clear(temp->root);
    clear(temp);
    *heap = NULL;
    return OK_HEAP;
}

   
HeapError destroy_left_child_data(Heap heap, AnyData d)
{
    if(heap == NULL)return DNE_HEAP;
    if(d == NULL)return DNE_HEAP;
    if(heap->size == 0)return FAIL_DELETE_HEAP;
    if(heap->size == 1)return FAIL_DELETE_HEAP;
    if(heap->contains(heap, d)==false)return DNF_HEAP;

    new_object(AnyData*, array, heap->size + 1);
    int oldSize = heap->size;
    CompareFunc comparator = heap->compareData;
    int count = 0;
    void* childData = heap->get_left_child(heap, d);
    if(childData == NULL){
        clear(array);
        return FAIL_DELETE_HEAP;
    }
    forall(oldSize){
        void* temp = heap->heapArray[x];
        if(comparator(childData, temp) != 0){
            array[count] = heap->heapArray[x];
            count++;
        }
    }
    clear(childData);
    clear(heap->heapArray);
    heap->heapArray = array;
    heap->root->data = heap->heapArray[0];
    (heap->size)--;

    set_heap_height(heap);
    return OK_HEAP;

}


HeapError destroy_right_child_data(Heap heap, AnyData d)
{
    if(heap == NULL)return DNE_HEAP;
    if(d == NULL)return DNE_HEAP;
    if(heap->size == 0)return FAIL_DELETE_HEAP;
    if(heap->size == 1)return FAIL_DELETE_HEAP;
    if(heap->contains(heap, d)==false)return DNF_HEAP;

    new_object(AnyData*, array, heap->size + 1);
    int oldSize = heap->size;
    CompareFunc comparator = heap->compareData;
    int count = 0;
    void* childData = heap->get_right_child(heap, d);
    if(childData == NULL){
        clear(array);
        return FAIL_DELETE_HEAP;
    }
    forall(oldSize){
        void* temp = heap->heapArray[x];
        if(comparator(childData, temp) != 0){
            array[count] = heap->heapArray[x];
            count++;
        }
    }
    clear(childData);
    clear(heap->heapArray);
    heap->heapArray = array;
    heap->root->data = heap->heapArray[0];
    (heap->size)--;

    set_heap_height(heap);
    return OK_HEAP;
   
}

HeapError destroy_parent_data(Heap heap, AnyData d)
{
    if(heap == NULL)return DNE_HEAP;
    if(d == NULL)return DNE_HEAP;
    if(heap->size == 0)return FAIL_DELETE_HEAP;
    if(heap->size == 1)return FAIL_DELETE_HEAP;
    if(heap->contains(heap, d)==false)return DNF_HEAP;
    int oldSize = heap->size;
    new_object(AnyData*, array, heap->size + 1);
    CompareFunc comparator = heap->compareData;
    int count = 0;
    void* parentData = heap->get_parent(heap, d);
    if(parentData == NULL){
        clear(array);
        return FAIL_DELETE_HEAP;
    }
    forall(oldSize){
        void* temp = heap->heapArray[x];
        if(comparator(temp, parentData) != 0){
            array[count] = heap->heapArray[x];
            count++;
        }
    }
   
    clear(parentData);
    clear(heap->heapArray);    
    heap->heapArray = array;
    heap->root->data = heap->heapArray[0];
    (heap->size)--;

    set_heap_height(heap);
    return OK_HEAP;
      
}
/***END DESTROYERS***/













































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

bool is_empty_heap(Heap heap)
{
    if(heap->size <= 0)return true;
    return false;
}

bool is_full_heap(Heap heap)
{
    if(heap->size == heap->capacity)return true;
    return false;
}
/***END VALIDATORS***/