
#ifndef _LIST_API_
#define _LIST_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
   void* data;
   struct listNode* next; 
}; typedef struct listNode ListNode;

struct list {
    ListNode* head;
    ListNode* tail;
    size_t size;
    void (*printFunc)(void* toBePrinted);
    void (*deleteFunc)(void* toBeDeleted);	
}; typedef struct list List;
/*
  just add to SinglyList tail
  readjust previous tail's next member to be the new node
*/
void insertBack(List* L, void* toBeAdded);
/*
    Function to return a List*
    Will need to make 26 Lists
    will add the list pointer to the hashTable pointers member for a list pointer
*/
List* initializeList(void (*print)(void* printData), void (*del)(void* deleteD));

/**
   Function to return a ListNode*
*/
ListNode* initializeNode(void* data);
/*
   hardest function to write, will have to go through the list, find the string that equals
   the void* data, find the index in the list that the node exists, at N, go to the List at 
   N-1, readjust that pointer's next member to pointer N's next member then remove pointer N
   step1: check if the pointer to remove is at the head
   step2: check if the pointer is in the middle
   step3: check if the pointer to remove is at the end
*/
void deleteNodeFromList(List* L, void* toBeDeleted);
/**
 Function to delete the entire list.
 Step 1: delete all the nodes
 step 2: free the list
**/
void deleteList(List* L);
/**
   creates a node for the list with a word as data
*/
ListNode* initializeListNode(void* toBeAdded);

void printForward(List* L);

#endif
