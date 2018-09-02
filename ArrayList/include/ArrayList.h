#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#include "utilities.h"
#include "DynamicString.h"
#include "LinkedList.h"

/**
 * NOTE TO USER: 
 *   The following pre-processor directives function expansions for functions found in this API.
 *   It is expected that the user will call the left hand expression in the pre-processor directive. I.E.
 *   the user will call the function get_from_front_arraylist(arg1, arg2, arg3). DO NOT call get_from_front_arraylist_real(arg1, arg2, &arg3)
 *      
 * */


/***PRE-PROCESSORS FOR DESTROYERS***/

#define destroy_arraylist(arrayList) destroy_arraylist_real(&arrayList)


enum ALError
{
    OK_ARRAYLIST,
    OUT_OF_MEM_ARRAYLIST,
    DNF_ARRAYLIST,
    DNE_ARRAYLIST,
    FAIL_ON_ADDING_ARRAYLIST,
    FAIL_ON_DELETING_ARRAYLIST,
    FAIL_ON_COPY_ARRAYLIST,
    DUPLICATE_LIST
};
typedef enum ALError ArrayListError;

struct al
{

    LinkedList *lists;
    //types indicate what type of data will be held in the list. Each type must be unique in ArrayList
    Strings types;
    unsigned int size;

    PrintFunc printArrayList;
    DeleteFunc deleteArrayList;
    CompareFunc compareArrayList;
    CloneFunc cloneArrayList;

    /***Object Oriented style. Function pointers to accessors, validators, setters, etc.
     *  All functions can be accessed via the arraylist.
     * ***/

    /**Function Pointers to Getters***/
    int (*get_size)(struct al *a);
    int (*get_length)(struct al *a, String type);
    LinkedList (*get_list)(struct al *a, String type);

    AnyData (*get_from_back)(struct al *a, String type);
    AnyData (*get_from_front)(struct al *a, String type);

    /***FUNCTION POINTERS TO CHECKERS AND VALIDATORS****/
    bool (*contains_data)(struct al *a, AnyData d);
    bool (*empty)(struct al *a);

    /***Function Pointers to Setters****/

    ArrayListError (*add)(struct al *a, String type, PrintFunc p, DeleteFunc d, CompareFunc c);
    ArrayListError (*insert_front)(struct al *a, String type, AnyData d);
    ArrayListError (*insert_back)(struct al *a, String type, AnyData d);
    ArrayListError (*insert_sorted)(struct al *a, String type, AnyData d);

    /***Function Pointers to Destroyers***/

    ArrayListError (*destroy_object)(struct al *a, AnyData d);
    ArrayListError (*remove)(struct al* a, String type);
    ArrayListError (*destroy)(struct al **a);

    /****Function Pointer to Sorters****/

    void (*sort)(struct al *a);
};
typedef struct al Arraylist;

typedef Arraylist *ArrayList;
typedef ArrayList *ArrayLists;

typedef int (*GetSizeFunc)(struct al *a);

/***********CONSTRUCTORS************/
ArrayList new_arraylist(PrintFunc p, DeleteFunc d, CompareFunc c);

/*************SETTERS**********/

/**
 * @param Arraylist, type, PrintFunc for data type, Delete Func for data type, Compare Func for data type
 * @returns status OK if list succcessfully added. Else Error. If type param = a tag in array list, then returns fail to add to array list.
 * @Function creates a new list and adds it to ArrayList a.
 * @New list is empty
 * @resizes ArrayList  if required.
 * @the user requires a type to be entered for the new list.
 * 
 * */
ArrayListError add_list(ArrayList a, String type, PrintFunc p, DeleteFunc d, CompareFunc c);

/**
 * Wrapper function for insertFront
 * @param arraylist, type, data
 * @return OK if successfully added, else DNF if type not associated with a list
 * */

ArrayListError insert_front_arraylist(ArrayList a, String type, AnyData d);

/**
 * Wrapper function for insertBack
 * @param arraylist, type, data
 * @return OK if successfully added, else DNF if type not associated with a list
 * */
ArrayListError insert_back_arraylist(ArrayList a, String type, AnyData d);

/**
 * Wraper function for insertSorted
 * See above setters for params and returns
 * Uses compare function pointer associated with the list for the type.
 * */
ArrayListError insert_sorted_arraylist(ArrayList a, String type, AnyData d);

/*********GETTERS***********/
LinkedList get_list(ArrayList a, String type);

int get_arraylist_size(ArrayList a);

int get_list_length(ArrayList a, String type);

/**Returns an error code. If data found then assigns data from the data at the back of the list of a given tupe to d. Does not alter list structure.
 *@pre The list exists and has memory allocated to it
 *@param the list struct
 *@return OK if data successfully added. Return DNF if type is not found. Returns DNE if data at back of list is NULL.
 *Uses preprocessor macro for expansion. CALL get_from_back_arraylist
 **/
AnyData get_from_back_arraylist(ArrayList a, String type);

/**Returns an error code. If data found then assigns data from the data at the front of the list of a given tupe to d. Does not alter list structure.
 *@pre The list exists and has memory allocated to it
 *@param the list struct
 *@return OK if data successfully added. Return DNF if type is not found. Returns DNE if data at back of list is NULL.
 *Uses preprocessor macro for expansion. CALL get_from_back_arraylist
 **/

AnyData get_from_front_arraylist(ArrayList a, String type);

/****CLONERS****/

LinkedList clone_list_real(ArrayList a, String type, CloneFunc c);

/********PRINTERS**********/

String print_arraylist(ArrayList a);

/**********DESTROYERS*************/

/**
 * Function to remove an entire list from an array list along with its associated type.
 * @param array list 
 * @param type
 * @rerturn OK_ARRAYLIST if successfully removed
 * @return DNF_ARRAYLIST if type match is unsuccessful
 * @return DNE_ARRAYIST if no list is associated with type.
**/
ArrayListError remove_list(ArrayList a, String type);

ArrayListError destroy_arraylist_real(ArrayList* a);

ArrayListError destroy_object_arraylist(ArrayList a, AnyData d);

/************VALIDATORS************/

bool contains_data_arraylist(ArrayList a, AnyData d);

bool empty_arraylist(ArrayList a);

bool contains_data_list(LinkedList l, AnyData d);

/****SORTERS****/

/***
 * Lexicographically sorts an ArrayList based on the types of the lists.
 * Sorting is CASE INSENSITIVE
 * @param arrayList a
 * @return sorted array list  based on types
 * 
 * */
void sort_arraylist(ArrayList a);

#endif