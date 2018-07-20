#ifndef _HEAP_
#define _HEAP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicString.h"
#include "utilities.h"


/***ENUM DEFINITIONS***/
enum ht{MIN, MAX}; 
typedef enum ht HeapType;

enum herr{OK_HEAP, DNF_HEAP, DNE_HEAP, OOM_HEAP, FAIL_ADD_HEAP, FAIL_DELETE_HEAP, MEM_ERR_HEAP};
typedef enum herr HeapError;
/****END ENUM DEFINITIONS****/


/*****META DATA AND PRE-PROCESSORS***/
unsigned long _____heapSizes[10] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

#define destroy_heap(heap) destroy_heap_real(&heap)

/***FIX ME***/
#define PARENT_INDEX(X) 


/***STRUCT DEFINITIONS****/
struct hn{
    void* data;
    struct hn* leftChild;
    struct hn* rightChild;
};
typedef struct hn heapode;
typedef heapnode* HeapNode;

struct h{
    HeapType heapType;
    String type;

    HeapNode root;
    AnyData* heapArray;
    unsigned long size;
    unsigned long capacity;
    unsigned long height;

    PrintFunc printData;
    DeleteFunc deleteData;
    CompareFunc compareData;

    
};

typedef h heap;
typedef heap* Heap;

/***END STRUCT DEFINITIONS***/



/***CONSTRUCTORS***/

HeapNode new_heap_node(AnyData data);

Heap new_default_heap(PrintFunc p, DeleteFunc d, CompareFunc c);

Heap new_heap(HeapType type, unsigned int size, PrintFunc p, DeleteFunc d, CompareFunc c);

/***END CONSTRUCTORS***/



/****ACCESSORS***/

AnyData get_heap_array(Heap heap);

unsigned long get_heap_capacity(Heap heap);

unsigned long get_heap_size(Heap heap);

unsigned long get_heap_height(Heap heap);

AnyData get_heap_data(Heap heap, AnyData d);

AnyData get_min_data(Heap heap);

AnyData get_max_data(Heap heap);

AnyData get_parent_data(Heap heap, AnyData d);

AnyData get_left_child_data(Heap heap, AnyData d);

AnyData get_right_child_data(Heap )

String get_heap_type(Heap heap);

/***END ACCESSORS***/



/***SETTERS****/

HeapError insert_data_heap(Heap heap, AnyData d);

HeapError resize_heap(Heap heap, int newSize);

HeapError set_heap_height(Heap heap);

/***END SETTERS***/


/****DESTROYERS***/

HeapError destroy_data_heap(Heap heap, AnyData d);

HeapError destroy_root_data_heap(Heap heap);

HeapError destroy_parent_object(Heap heap, AnyData d);

HeapError destroy_left_child_data(Heap heap, AnyData d);

HeapError destroy_right_child_data(Heap heap, AnyData d);

HeapError destroy_heap_real(Heap* heap);

/****END DESTROYERS***/


/***MUTATORS***/

String heap_to_string(Heap heap);

/***END MUTATORS***/


/***VALIDATORS****/

bool is_empty_heap(Heap heap);

bool is_full(Heap heap);

bool contains_data_heap(Heap heap, AnyData d);

/***END VALIDATORS***/


#endif