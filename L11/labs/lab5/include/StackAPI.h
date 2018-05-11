#ifndef STACK_API
#define STACK_API

#include "LinkedListAPI.h"

typedef struct stack {
    List *list;
    int count;
} Stack;

/** Allocates Memory for a stack, creates a list with function pointers and set count to 0
*@return A Stack Structure
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
Stack* initializeStack(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**
 * Push data onto the stack
 * @param stack     Stack
 * @param toBeAdded  pointer to datatype
 */
void push(Stack *stack, void *toBeAdded);

/**
 * Return the top of the stack or NULL
 * @param stack
 */
void* top(Stack *stack);

/**
 * Note: You could return void* if you wanted in your API 
 		I'm not since we already have top.
 * Pops the item off the stack.
 * @param stack [description]
 */
void pop(Stack *stack);
 
 /**
  * Count the items in the stack, this is an accessor
  * @param  s [description]
  * @return   [description]
  */
int count(const Stack * s);

/**
 * This is a helper function for a common action.
 * Just checks if the count(...) == 0
 * @param  s [description]
 * @return   [description]
 */
int isEmpty( Stack* s);

/**
 * Essentially, everything here is handled by the List interface
 * Your only dynamic memory is the list which has a delete function.
 * @param stack [description]
 */
void deleteStack(Stack *stack);

#endif
