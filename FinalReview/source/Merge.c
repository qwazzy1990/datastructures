#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Merge.h"

int* merge(int* left, int* right){
   
    int* mergedArray = (int*)malloc(sizeof(int)*30);
    int i = 0;
    int leftSize = sizeof(left)/sizeof(int);
    int rightSize = sizeof(right)/sizeof(int);
    while(i < leftSize && i < rightSize){
	    if(left[i] > right[i]){
	        mergedArray[i] = left[i];
	    }
	    else {
	        mergedArray[i] = right[i];
	    }
	    printf("Inside merge: mergeArray[i] is %d\n", mergedArray[i]);
	    i++;
    }
    if(i < leftSize){
	while(i < leftSize){
	    mergedArray[i] = left[i];
	    printf("Inside merge: mergeArray[i] is %d\n", mergedArray[i]);
	    i++;
	}
    }
    else {
	while(i < rightSize){
	    mergedArray[i] = right[i];
	    printf("Inside merge: mergeArray[i] is %d\n", mergedArray[i]);
	    i++;
	}
    }
    return mergedArray;
}

int* mergeSort(int* arr){
   

    int partition = 0;
    int* leftArr = NULL;
    int* rightArr = NULL;
    //int* mergedArr = (int*)malloc(sizeof(int)*30);
    int size = sizeof(arr)/sizeof(int);
    if(size > 2){
	partition = size/2;
        leftArr = mergeSort(getPartition(arr, 0, partition));
        rightArr = mergeSort(getPartition(arr, partition+1, size));
        return merge(leftArr, rightArr);      
    }
    else {
	return arr;
    }
}

int* getPartition(int* arr, int start, int end)
{
    int* newArr = (int*)malloc(sizeof(int)*(end - start));
    int i = 0;
    while(start < end){
	newArr[i] = arr[start];
        i++;
        start++;
    }
    return newArr;
}
