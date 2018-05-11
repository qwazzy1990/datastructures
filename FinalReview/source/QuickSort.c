#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuickSort.h"

int partition(int Arr[], int low, int high)
{
    int pivot = Arr[high];
    int i = 0;
    int j = 0;
    for(i = low; i < high; i++){
	for(j = i; j < high-1; j++){
	    if(Arr[i] > Arr[j]){
		int temp = Arr[i];
		Arr[i] = Arr[j];
		Arr[j] = temp;
	    }
	}
    }
    for(i = low; i < high; i++){
	if(Arr[i] == pivot){
	    break;
	}
    }
    return i;
}

void quickSort(int Arr[], int start, int end)
{
    if(start < end){
        int part = partition(Arr, start, end);
	quickSort(Arr, start, part-1);
        quickSort(Arr, part+1, end);
    }


}
