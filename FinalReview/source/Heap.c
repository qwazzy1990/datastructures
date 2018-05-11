
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heap.h"

void heapify(int arr[], int size, int index)
{
    int largest = index;
    int L = 2*index  + 1;
    int R = 2*index + 1;
    if(L < size && (arr[L] > arr[index])){
	largest = L;
    }
    if(R < size && (arr[R] > arr[index])){
	largest = R;
    }
    if(largest != index){
	int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);

    }
}

void heapSort(int arr[], int size)
{

    while(size > 1){
	int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
	heapify(arr, size, 0);
	size--;
    } 

}
