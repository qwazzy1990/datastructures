#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ArrayList.h"

/*****STATIC FUNCTIONS: NO DIRECT CALL IN API. NOT AVAILABLE TO USERS*****/

static void swap_types(Strings a, Strings b)
{
    String temp = (*a);
    *a = (*b);
    *b = temp;
}

static void swap_lists(LinkedList *a, LinkedList *b)
{
    LinkedList temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

static int partition_arraylist(ArrayList a, int low, int high)
{
    String pivot = to_upper(a->types[high]);
    int i = low - 1;
    foreach (low, high)
    {
        String upperCase2 = to_upper(a->types[x]);
        if (strcmp(upperCase2, pivot) <= 0)
        {
            i++;
            swap_types(&(a->types[x]), &(a->types[i]));
            swap_lists(&(a->lists[x]), &(a->lists[i]));
        }
        destroystring(upperCase2);
    }
    swap_types(&(a->types[high]), &(a->types[i + 1]));
    swap_lists(&(a->lists[high]), &(a->lists[i + 1]));
    destroystring(pivot);
    return i + 1;
}
static void quicksort_arraylist(ArrayList a, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition_arraylist(a, low, high);
        quicksort_arraylist(a, low, partitionIndex - 1);
        quicksort_arraylist(a, partitionIndex + 1, high);
    }
}




/*****CONSTRUCTORS*****/
ArrayList new_arraylist(PrintFunc p, DeleteFunc d, CompareFunc c)
{
    new_object(ArrayList, a, 1);
    assert(a != NULL);
    a->printArrayList = p;
    a->deleteArrayList = d;
    a->compareArrayList = c;
    /***FUNCTION POINTERS TO GETTERS****/
    a->get_arraylist_size = get_arraylist_size;
    a->get_list_length = get_list_length;
    a->get_list = get_list;
    a->get_from_back_arraylist = get_from_back_arraylist;
    a->get_from_front_arraylist = get_from_front_arraylist;

    /**Function Pointers to Checkers and Validators****/

    //a->contains_data_arraylist = contains_data_arraylist;
    a->empty_arraylist = empty_arraylist;

    /****Function Pointers to Setters****/

    a->add_list = add_list;
    a->insert_back_arraylist = insert_back_arraylist;
    a->insert_front_arraylist = insert_front_arraylist;
    a->insert_sorted_arraylist = insert_sorted_arraylist;

    /***Function Pointers to Destroyers***/

    a->destroy_arraylist = destroy_arraylist_real;
    a->remove_list = remove_list;
    a->destroy_object_arraylist = destroy_object_arraylist;

    /***Function Pointer to Sorter***/

    a->sort_arraylist = sort_arraylist;

    a->size = 0;
    a->lists = NULL;
    a->types = NULL;
    return a;
}

/******CLONERS******/

ListNode clone_node(ListNode n)
{
    if (n == NULL)
        return NULL;
    if (n->data == NULL)
        return NULL;

    new_object(ListNode, clone, 1);
    clone->data = n->data;
    clone->next = NULL;
    clone->previous = NULL;
    return clone;
}

/******SETTERS******/

ArrayListError add_list(ArrayList a, String type, PrintFunc p, DeleteFunc d, CompareFunc c)
{
    if(a == NULL){
        return DNE_ARRAYLIST;
    }
    if(type == NULL){
        return DNE_ARRAYLIST;
    }

    if(stringlen(type) <=0){
        return DNE_ARRAYLIST;
    }
    if( p == NULL || d == NULL || c==NULL){
        return DNE_ARRAYLIST;
    }
    if(a->size == 0){
        a->lists = calloc(2, sizeof(LinkedList));
        a->lists[0] = new_linkedlist(p, d, c);
        a->types = calloc(2, sizeof(String));
        a->types[0] = stringcopy(type);
        a->size++;
        a->lists[1] = NULL;
        a->types[1] = NULL;
        return OK_ARRAYLIST; 
    }

    forall(a->size){
        if(strequal(type, a->types[x], CASE_INSENSITIVE)){
            return DUPLICATE_LIST;
        }
    }
    int index = a->size;
    int memSize = (a->size)+2;
    a->lists = realloc(a->lists, sizeof(LinkedList)*memSize);
    a->types = realloc(a->types, sizeof(String)*memSize);
    a->lists[index] = new_linkedlist(p, d, c);
    a->types[index] = stringcopy(type);
    a->size++;
    index = a->size;
    a->lists[index] = NULL;
    a->types[index] = NULL;

    return OK_ARRAYLIST;

}

ArrayListError insert_front_arraylist(ArrayList a, String type, AnyData d)
{
    if(a == NULL){
        return DNE_ARRAYLIST;
    }
    if(type == NULL){
        return DNE_ARRAYLIST;
    }
    if(stringlen(type)<=0){
        return DNE_ARRAYLIST;
    }

    if(d == NULL){
        return DNE_ARRAYLIST;
    }
    int index = -1;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }  
    }
    if(index == -1){
        return DNF_ARRAYLIST;
    }
    ListErrorCode listError = insert_front(a->lists[index], d);
    if(listError == OK_LIST){
        return OK_ARRAYLIST;
    }else{
        return FAIL_ON_ADDING_ARRAYLIST;
    }
}

ArrayListError insert_back_arraylist(ArrayList a, String type, AnyData d)
{
    if(a == NULL){
        return DNE_ARRAYLIST;
    }
    if(type == NULL){
        return DNE_ARRAYLIST;
    }
    if(stringlen(type)<=0){
        return DNE_ARRAYLIST;
    }

    if(d == NULL){
        return DNE_ARRAYLIST;
    }
    int index = -1;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }  
    }
    if(index == -1){
        return DNF_ARRAYLIST;
    }
    ListErrorCode listError = insert_back(a->lists[index], d);
    if(listError == OK_LIST){
        return OK_ARRAYLIST;
    }else{
        return FAIL_ON_ADDING_ARRAYLIST;
    }
}

ArrayListError insert_sorted_arraylist(ArrayList a, String type, AnyData d)
{
    if(a == NULL){
        return DNE_ARRAYLIST;
    }
    if(type == NULL){
        return DNE_ARRAYLIST;
    }
    if(stringlen(type)<=0){
        return DNE_ARRAYLIST;
    }

    if(d == NULL){
        return DNE_ARRAYLIST;
    }
    int index = -1;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }  
    }
    if(index == -1){
        return DNF_ARRAYLIST;
    }
    ListErrorCode listError = insert_sorted(a->lists[index], d);
    if(listError == OK_LIST){
        return OK_ARRAYLIST;
    }else{
        return FAIL_ON_ADDING_ARRAYLIST;
    }
}


/***END SETTERS***/




/************GETTERS*********/

LinkedList get_list(ArrayList a, String type)
{
    if(a == NULL)return NULL;
    if(type == NULL)return NULL;
    if(stringlen(type)<=0)return NULL;
    int index = -1;
    if(a->size == 0)return NULL;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }
    }
    if(index == -1)return NULL;
    return a->lists[index];
}

AnyData get_from_back_arraylist(ArrayList a, String type)
{
    if(a == NULL)return NULL;
    if(type == NULL)return NULL;
    if(stringlen(type)<=0)return NULL;
    int index = -1;
    if(a->size == 0)return NULL;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }
    }
    if(index == -1)return NULL;
    AnyData d = get_from_back(a->lists[index]);
    return d;
}

AnyData get_from_front_arraylist(ArrayList a, String type)
{
   if(a == NULL)return NULL;
    if(type == NULL)return NULL;
    if(stringlen(type)<=0)return NULL;
    int index = -1;
    if(a->size == 0)return NULL;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }
    }
    if(index == -1)return NULL;
    AnyData d = get_from_front(a->lists[index]);
    return d;
}

int get_arraylist_size(ArrayList a)
{
    if (a == NULL)
        return -1;
    return a->size;
}

int get_list_length(ArrayList a, String type)
{
    if(a == NULL)return -1;
    if(type == NULL)return -1;
    if(stringlen(type)<=0)return -1;
    int index = -1;
    if(a->size == 0)return -1;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }
    }
    if(index == -1)return -1;
    int len = get_length(a->lists[index]);
    return len;
}

/***END GETTERS***/

/****************PRINTERS*************/

String print_arraylist(ArrayList a)
{
    assert(a != NULL);
    String printer = createvoidstring();
    String descr = NULL;
    String str = NULL;
    forall(a->size){
        String temp = createvoidstring();
        descr = list_to_string(a->lists[x]);
        str = stringcopy(a->types[x]);
        strcat(temp, str);
        strcat(temp, descr);
        Strings splitter = stringsplit(temp, "\n");
        clear(temp);
        strcat(printer, splitter[0]);
        strcat(printer, "\n");
        int i = 1;
        while(splitter[i] != NULL){
            strcat(printer, splitter[i]);
            strcat(printer, "\n");
            i++;
        }
        strcat(printer, "\n");
        clear(descr);
        clear(str);
        destroystringarray(splitter);
    }
    return printer;
}

/****DESTROYERS****/
ArrayListError destroy_arraylist_real(ArrayList* a)
{
    assert(a != NULL);
    if(*a == NULL)return FAIL_ON_DELETING_ARRAYLIST;

    if((*a)->size == 0){
        clear(*a);
        *a = NULL;
        return OK_ARRAYLIST;
    }
    int size = (*a)->size;
    int indecies[size];
    forall(size){
        indecies[x] = -1;
    }
    int count = 0;
    forall(size){
        ListErrorCode listError = destroy_list((*a)->lists[x]);
        if(listError != OK_LIST){
            indecies[count] = x;
            count++;
        }

    }
    if(indecies[0] != -1){
        return FAIL_ON_DELETING_ARRAYLIST;
    }
    destroystringarray((*a)->types);
    clear((*a)->lists);
    clear(*a);

    return OK_ARRAYLIST;
}

ArrayListError remove_list(ArrayList a, String type)
{

    if(a == NULL)return DNE_ARRAYLIST;
    if(type == NULL)return DNE_ARRAYLIST;
    if(stringlen(type)<=0)return DNE_ARRAYLIST;

    if(a->size == 0)return DNE_ARRAYLIST;

    int index = -1;
    forall(a->size){
        if(strequal(a->types[x], type, CASE_INSENSITIVE)){
            index = x;
        }
    }
    if(index == -1)return DNF_ARRAYLIST;
    ListErrorCode listCode = destroy_list(a->lists[index]);
    if(listCode == OK_LIST){
        int size = a->size;
        int count = index+1;
        int remaining = a->size - count;
        forall(remaining){
            a->lists[count-1] = a->lists[count];
            count++;
        }
        remove_from_stringarray(a->types, a->types[index]);
        a->size--;
        size = a->size;
        a->lists[size] = NULL;
        a->types[size] = NULL;
        return OK_ARRAYLIST;
    }else{
        return FAIL_ON_DELETING_ARRAYLIST;
    }
    
}

ArrayListError destroy_object_arraylist(ArrayList a, AnyData d)
{
    if (a == NULL)
        return DNE_ARRAYLIST;
    if (d == NULL)
        return DNE_ARRAYLIST;

    if(a->size == 0)return DNE_ARRAYLIST; 
    
    forall(a->size){
        LinkedList temp = get_list(a, a->types[x]);
        if(temp == NULL){
            return OUT_OF_MEM_ARRAYLIST;
        }
        ListErrorCode listError = destroy_object_list(temp, d);
        if(listError == OK_LIST){
            return OK_ARRAYLIST;
        }
    }
    return DNF_ARRAYLIST;
}


/***END DESTROYERS***/




bool empty_arraylist(ArrayList a)
{
    if (a->size == 0)
        return true;
    return false;
}

/*****SORTERS*****/

void sort_arraylist(ArrayList a)
{
    if (a == NULL)
        return;
    quicksort_arraylist(a, 0, (a->get_arraylist_size(a) - 1));
}