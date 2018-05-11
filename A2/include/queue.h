
#ifndef _QUEUE_
#define _QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"

struct queue {
   void(*printFunc)(void* data);
   void(*deleteFunc)(void* data);
   int (*compareFunc)(int a, int b);
    Node* head;
    Node* tail;
}; typedef struct queue Queue;

void insertBackQ(Queue* q, Node* newNode);
void insertSortedQ(Queue* q, Node* newNode);
Node* initializeNodeQ(void* data);
Queue* initializeQueue(void(*print)(void* printData), void(*deleteNode)(void* del), int(compare)(int a, int b));
int compareQ(int a, int b);
void readFile(FILE* fp, Queue* q, Queue* q2);
void enqueue(List* L, void* data);
void dequeue(List* L, void* data);
void* peek(List* L);
#endif
