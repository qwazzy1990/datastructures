
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SinglyLinkedListAPI.h"
#include "HashTableAPI.h"
#include "WordAPI.h"

List* initializeList(void(*print)(void* printData), void(*del)(void* deleteD))
{
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    l->printFunc = print;
    l->deleteFunc = del;
    return l;
}

void deleteList(List* List)
{
     if(List == NULL) {
       printf("List is empty\n");
       return;
     }
     ListNode* iterator = NULL;
     iterator = List->head;
     void* temp = NULL;    
     while(iterator != NULL) {
          temp = iterator;

          iterator = iterator->next;

          free(temp);
      }
     
     free(List);
}

void insertBack(List* L, void* toBeAdded)
{
    ListNode* newNode = initializeListNode(toBeAdded);

    ListNode* oldTail = NULL;   
    if(L->tail == NULL && L->head == NULL){
	printf("adding word %s\n", (char*)newNode->data);
	L->head = newNode;
	L->tail = newNode;
	L->size += 1;
	return;
    }
    else if(L->head == L->tail){
	printf("adding word %s\n", (char*)newNode->data);
	L->tail->next = NULL;
	L->tail = newNode;
	L->head->next = newNode;
	L->size += 1;
	return;
    }
    else {
	printf("adding word %s\n", (char*)newNode->data);
	oldTail = L->tail;
	oldTail->next = newNode;
	L->tail = newNode;
	L->tail->next = NULL;
        L->size += 1;
	return;
    }
}

ListNode* initializeListNode(void* toBeAdded)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = toBeAdded;
    newNode->next = NULL;
    return newNode;
}

void deleteNodeFromList(List* L, void* toBeDeleted)
{
     char* destroy = (char*)toBeDeleted;
     ListNode* previous = NULL;
     ListNode* nodeToDestroy = L->head;
     int i = 0;
     char finder[1000][1000];
     strcpy(finder[i], (char*)nodeToDestroy->data);
     if(strcmp(finder[i], destroy)==0){
	printf("Deleting word %s\n", finder[i]);
	L->head = L->head->next;
	L->size -= 1;
	free(nodeToDestroy);
	return;
     }
     while(nodeToDestroy != NULL && (!(strcmp(finder[i], destroy)==0))) {
         previous = nodeToDestroy;
         nodeToDestroy = nodeToDestroy->next;
	 i++;
	 if(nodeToDestroy != NULL){
	     strcpy(finder[i], (char*)nodeToDestroy->data);
	 }
     }
     if(nodeToDestroy == NULL){
         printf("The word cannot be deleted because it does not exist\n");
         return;
     }
     printf("deleting word %s\n", finder[i]);
     if(i == 1000000000){
         previous->next = nodeToDestroy->next;
     }
     if(nodeToDestroy != NULL){
         previous->next = nodeToDestroy->next;
         free(nodeToDestroy);
     }
     L->size -= 1;
}

void printForward(List* L)
{
    ListNode* iterator = NULL;
    if(L->size > 0){

	iterator = L->head;
	while(iterator != NULL){
	    printString(iterator->data);
	    iterator = iterator->next;
	}
     }
}
