#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "LinkedListAPI.h"
#include "patient.h"

void insertSortedQ(Queue* q, Node* newNode)
{
    Node* iterator = NULL;
    iterator = q->head;
    if(q->head == NULL) {
	q->head = newNode;
	q->tail = newNode;
	q->head->next = q->tail;
	q->head->previous = NULL;
	q->tail->previous = q->head;
	q->tail->next = NULL;
	return;
    }
    if(q->head == q->tail) {
	if(q->head->priority > newNode->priority) {
	    q->head = newNode;
	    newNode->next = q->tail;
	    q->tail->previous = q->head;
	    q->head->next = q->tail;
	}
        else if(q->head->priority <= newNode->priority){
	    q->tail = newNode;
	    newNode->previous = q->head;
	    newNode->next = NULL;
	    q->head->next = q->tail;
	    q->head->previous = NULL;
	}
	return;
    }
    else {
	while(q->head != NULL) {
            if(iterator->priority > newNode->priority) {
		newNode->next = q->head;
		q->head->previous = newNode;
		newNode->previous = NULL;
		q->head = newNode;
		return;
	    }
	    if(q->tail->priority < newNode->priority) {
		newNode->previous = q->tail;
		newNode->next = NULL;
		q->tail->next = newNode;
		q->tail = newNode;
		return;
	    }
            if((q->head->priority == newNode->priority)) {
		newNode->next = q->head->next;	
		newNode->previous = q->head;
		//q->head->next->previous = newNode;
		q->head->next = newNode;
		break;
	    }
	    if((q->head->priority < newNode->priority)&&
            (q->head->next->priority > newNode->priority)) {
		newNode->next = q->head->next;
		newNode->previous = q->head;
		q->head->next->previous = newNode;
		q->head->next = newNode;
		break;
	    }
	    q->head = q->head->next;	

       }
	
    }
    q->head = iterator;


    return;
}


int compareQ(int a, int b)
{

    if(a > b) {
	return 1;
    }
    else if(a == b) {
	return 0;
    }
    else {
	return -1;
    }
}

Node* initializeNodeQ(void* data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    Patient* temp = (Patient*)data;
    newNode->priority = temp->y;
    return newNode;
}

Queue* initializeQueue(void(*print)(void* printData), void(*deleteNode)(void* del), int(*compare)(int a, int b))
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->printFunc = print;
    newQueue->deleteFunc = deleteNode;
    newQueue->compareFunc = compare;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

void insertBackQ(Queue* q, Node* newNode)
{

     if(q->tail == NULL) {
  	q->tail = newNode;
  	q->head = newNode;
   	q->head->next = q->tail;
    	q->head->previous = NULL;
     	q->tail->next = NULL;
      	q->tail->previous = q->head;
        return;
      }
      if(q->head == q->tail){
	newNode->previous = q->head;
	newNode->next = NULL;
	q->head->next = newNode;
	q->tail = newNode;
	q->tail->previous = q->head;
	q->head->next = q->tail;
	q->head->previous = NULL;
	q->tail->next = NULL;
	return;
	
      }
      newNode->previous = q->tail;
      newNode->next = NULL;
      q->tail->next = newNode;
      q->tail = newNode;
      return;

}

void readFile(FILE* fp, Queue* q, Queue* q2)
{
    char s[10] = "\0";
    int k = 0;
    char t[10] = "\0";
    //Patient* newPatient = NULL;
    Node* newNode = NULL;
    Node* newNode2 = NULL;
    while(!feof(fp)) {
          fscanf(fp, "%s %d %s", s, &k, t);
          if(feof(fp) == 1) {
              return;
          }
          newNode = initializeNodeQ(initializePatient(s, &k, t));
	  newNode2 = initializeNodeQ(initializePatient(s, &k, t));
          insertSortedQ(q, newNode);
	  insertBackQ(q2, newNode2);
    }
    return;
}
void enqueue(List* L, void* data)
{
   insertBack(L, data);
}

void dequeue(List* L, void* data)
{
    deleteNodeFromList(L, data);
}
