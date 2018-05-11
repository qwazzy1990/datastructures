#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

Stack* initializeStack(int(*compare)(const void* a, const void* b))
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->head = NULL;	
    s->tail = NULL;
    s->compareFunc = compare;
    s->printFunc = NULL;
    s->deleteFunc = NULL;
    return s;
}
void pop(Stack* s)
{
    Node* temp = NULL;
    if(s->head == NULL) {
	return;
	
    }
    else {
	temp = s->head;	
        if(s->head->next == NULL) {
	    printf("head next is null\n");
	    s->head = NULL;
	    free(s->head);
	    return;
        }
        else {
 	    printf("head next is not null\n");
	    s->head = s->head->next;
	    s->head->previous = NULL;
	    free(temp);
	    return;
        }
    }

}

void push(Stack* s, void* data)
{
    Node* tempHead = NULL;
    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->data = data;
    newHead->next = NULL;
    newHead->previous = NULL;
    if(s->head == NULL) {
        printf("head is null in push\n");
	s->head = newHead;
	return;
    }
    else {
        printf("head is not null in push\n");
	newHead->next = s->head;
	s->head->previous = newHead;	
	newHead->previous = NULL;
	s->head = newHead;
	return;
    }
}

void* top(Stack* s)
{
    void* temp = NULL;
    if(s->head == NULL) {
	return temp;
    }
    else {
	printf("%d\n", *(int*)(s->head->data));
	return s->head->data;
    }
}

int count(Stack* s)
{
    Node* iterator = NULL;
    int counter = 0;
    if(s->head == NULL) {
	return 0;
    }    
    else {
	iterator = s->head;
        while(iterator != NULL) {
	    printf("%d ", *(int*)iterator->data);
	    iterator = iterator->next;
	    counter++;
	}
	return counter;
    }
}

int compareStack(const void* a, const void* b)
{
    int* x = NULL;
    int* y  = NULL;
    x = (int*)a;
    y = (int*)b;
    if(*x > *y) {
	return 1;
    }
    else if(*x == *y) {
	return 0;
    }
    else {
	return -1;
    }
}


