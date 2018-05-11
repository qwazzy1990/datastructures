#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "car.h"

void deleteListNode(void* toBeDeleted)
{
    Car* tempCar = NULL;
    tempCar = (Car*)toBeDeleted;
    if(tempCar == NULL){
	printf("Node does not exist\n");
	return;
    } 
    else{
	free(tempCar);
	return;
    }
}

Node* initializeNode(void* data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(List* List, void* toBeAdded)
{
    void* data = toBeAdded;
    Node* newHead = NULL;
    Node* oldHead = List->head;
    newHead = initializeNode(data);
    if(List->head == NULL) {

	newHead->next = NULL;
	newHead->previous = NULL;
	List->head = newHead;
	return;
    }
    newHead->next = oldHead;
    newHead->previous = NULL;
    oldHead->previous = newHead;
    List->head = newHead;
    return;
}

void insertBack(List* List, void* toBeAdded)
{
    void* data = toBeAdded;
    Node* newTail = NULL;
    Node* oldTail = NULL;
    oldTail = List->tail;
    newTail = initializeNode(data);
    if(List->tail == NULL) {

	newTail->next = NULL;
	newTail->previous = NULL;
	List->tail = newTail;
	List->head = newTail;
	List->tail->previous = NULL;
	List->tail->next = NULL;
	List->head->next = NULL;
	List->head->previous = NULL;
	return;
    }
    newTail->previous = oldTail;
    newTail->next = NULL;
    oldTail->next = newTail;
    List->tail = newTail;

    return;
}   

void insertSorted(List* List, void* toBeAdded) 
{
    void* data = toBeAdded;
    Node* iterator = NULL;
    iterator = List->head;
    Node* newNode = initializeNode(data);
    Node* tempNext = NULL;
    Node* tempPrev = NULL;
    int retVal = -10;
    int retVal2 = -10;
    if(List->head == NULL) {
	List->head = newNode;
	List->tail = newNode;
	List->head->next = List->tail;
	List->head->previous = NULL;
	List->tail->previous = List->head;
	List->tail->next = NULL;
	return;
    }
    if(List->head == List->tail) {
	retVal = compareCars(List->head->data, newNode->data);
	if(retVal >= 0) {
	    List->tail->previous = newNode;
	    List->tail->next = NULL;
	    newNode->next = List->tail;
	    newNode->previous = NULL;
	    List->head = newNode;
	    List->head->previous = NULL;
	    List->head->next = List->tail;
	    return;
        }
	else {
	    List->head->next = newNode;
	    newNode->previous = List->head;
	    List->tail = newNode;
	    return;
	}
    }
    iterator = List->head;
    while(List->head != NULL) {
        retVal = compareCars(List->head->data, newNode->data);
	retVal2 = compareCars(List->head->next->data, newNode->data);
	if((retVal == -1) && (retVal2 == 1)) {
            tempNext = List->head->next;
            tempPrev = List->head;
	    newNode->previous = tempPrev;
	    newNode->next = tempNext;
	    List->head->next = newNode;
	    tempNext->previous = newNode;
	    break;
        }
    List->head = List->head->next;
    }
    List->head = iterator; 
    return;   
}

void printNode(void* toBePrinted)
{
    Car* printCar = toBePrinted;
    printf("%c%c%.2lf\n", printCar->lane, printCar->direction, 
    printCar->arrivalTime);
}

List* initializeList(void (*printFunction)(void* toBePrinted), void (*deleteFunction) (void* toBePrinted), int (*compareFunction)(const void* first, const void* second)) 
{
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->deleteNode = deleteFunction;
    newList->printNode = printFunction;
    newList->compare = compareFunction;
    return newList;
}

void printForward(List* List) {
    Node* iterator = NULL;
    iterator = List->head;
    while(iterator != NULL) {
	List->printNode(iterator->data);
	iterator = iterator->next;
    }
    return;
}

void printBackwards(List* List)
{
    Node* iterator = NULL;
    iterator = List->tail;
    while(iterator != NULL) {
	List->printNode(iterator->data);
	iterator = iterator->previous;
    }
    return;
}

void* getFromFront(List* List)
{
    return List->head->data;
}

void* getFromBack(List* List) 
{
    return List->tail->data;
}

int deleteNodeFromList(List* List, void* toBeDeleted)
{
    Node* iterator = NULL;
    void* tdata;
    int k = 0;
    int flag = 0;
    iterator = List->head;
    if(iterator->next == NULL) {
	tdata = iterator->data;
	iterator->previous = NULL;
	iterator = NULL;

	List->head = iterator;
	deleteListNode(tdata);
	free(iterator);
	flag = 1;
	return flag;
    }
    while(iterator != NULL) {
	k = compareCars(iterator->data, toBeDeleted);

	if(k == 0) {
	    tdata = iterator->data;
	    iterator->previous->next = iterator->next;
	    iterator->next->previous = iterator->previous;
	    List->head->previous = NULL;
	    deleteListNode(tdata);
	    free(iterator);
	    flag = 1;
	    return flag;
	}
	iterator = iterator->next;
   }
   return flag;
}
void deleteList(List* List)
{
    if(List == NULL) {
	printf("List is empty\n");
	return;
    }
    Node* iterator;
    iterator = List->head;
    Node* temp = NULL;
    void* temp2 = NULL;
    if(List) {
        while(iterator != NULL) {
	    temp = iterator;
	    temp2 = iterator->data;
	    iterator = iterator->next;
	    free(temp2);
	    free(temp);
        }
    }
    free(List);
}











































