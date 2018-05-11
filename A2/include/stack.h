#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
   data structure 
*/
struct stack {
    void (*printFunc)(void* toBePrinted);
    void (*deleteFunc)(void* toBeDeleted);
    int (*compareFunc)(const void* a, const void* b);
    struct node* head;
    struct node* tail;
};typedef struct stack Stack;
/**
    generic data container
*/
struct node {
    void* data;
    struct node* next;
    struct node* previous;
};typedef struct node Node;
/**
    @param - stack
    @return void
    @removes data at top of stack
*/
void pop(Stack* s);
/**
    @param - stack, void*
    @return - NA
    @adds new value to top of stack
*/
void push(Stack* s, void* data);
/**
    @param - stack
    @return - value at top of stack
    @accesses value at top of stack
*/
void* top(Stack* s);
/**
    @param stack
    @return integer = number of elements in stack
*/
int count(Stack* s);
/**
    @param two pointers
    @return: 1 if *a > *b, 0 if *a = *b, else -1
*/
int compareStack(const void* a, const void* b);
/**
    @param - function pounter
    @return - a stack pointer
*/
Stack* initializeStack(int(*compare)(const void* a, const void* b));
