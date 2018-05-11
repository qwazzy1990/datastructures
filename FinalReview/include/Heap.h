#ifndef _HEAP_
#define _HEAP_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct eap{
    struct eap* left;
    struct eap* right;
    int data;

}; typedef struct eap Heap;

void heapify(int arr[], int size, int index);
void heapSort(int arr[], int size);







#endif
