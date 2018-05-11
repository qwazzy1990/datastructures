#include "sorterMain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char* menuSelection, void (*s)(int x[], int(*compare)(const void* a, const
void* b), int z), int* array, int length, int comp(const void* a, const void* b))
{
    s(array, comp, length);
}
void bubbleSortAscending(int* x, int(*compare)(const void* a, const void* b), int size)
{
    int i;
    int j;
    int temp = 0;
    for(i = 0; i < size; i++) {
	for(j = i; j < (size); j++){
            if(j != (size-1))
	    if(compare(&x[j], &x[j+1]) == 1) {
		temp = x[j];
		x[j] = x[j+1];
		x[j+1] = temp;
	    }
	}

    }
    for(i = 0; i < size; i++){
	printf("%d\n", x[i]);
    }
}
void bubbleSortDescending(int* x, int(*compare)(const void* a, const void* b), int size)
{
    int i;
    int j;
    int temp2 = 0;
    for(i = 0; i < size; i++) {
	for(j = i; j < (size); j++) {
	    if(j != (size - 1))
	    if(x[j] > x[j+1]) {
		temp2 = x[j+1];
		x[j+1] = x[j];
		x[j] = temp2;
	    }
	}
    }
 }
void bubbleSortEven(int* x, int (*compare)(const void* a, const void* b), int size){
    int* aEven = (int*)malloc(sizeof(int));
    int* aOdd = (int*)malloc(sizeof(int));
    int i = 0;
    int counter = 0;
    int counter2 = 0;
    int j = 0;
    int temp = 0;
    int temp2 = 0;
   
    for(i = 0; i < size; i++) {
	if((x[i]%2) == 0){
	    aEven[counter] = x[i];
	    aEven = (int*)realloc(aEven, sizeof(int));
	    counter++;
	}
    }
    for(i = 0; i < size; i++) {
	if((x[i]%2) == 1) {
	    aOdd[counter2] = x[i];
	    aOdd = (int*)realloc(aOdd, sizeof(int));
	    counter2++;
	}
    }
    for(i = 0; i < counter; i++) {
	for(j = i; j < (counter); j++){ 
	    if(j != counter-1)
	        if(aEven[j] > aEven[j+1]) {
		    temp = aEven[j];
		    aEven[j] = aEven[j+1];
		    aEven[j+1] = temp;

	        }
	}
    }
    for(i = 0; i < counter2; i++) {
	for(j = i; j < counter2; j++){
	    if(j != counter2 - 1)
	    if(aOdd[j] > aOdd[j+1]){
		temp2 = aOdd[j];
		aOdd[j] = aOdd[j+1];
		aOdd[j+1] = temp2;
	    }

	}
    }
    for(i = 0; i < counter; i++) {
	printf("%d\n", aEven[i]);
    }
    for(i = 0; i < counter2; i++){
	printf("%d\n", aOdd[i]);
    }
}

void insertionSortAscending(int* x, int (*comp)(const void* a, const void* b), int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while(i < size){
	j = i;
	while((j > 0)&&(x[j-1]>x[j])){
	    temp = x[j];
	    x[j] = x[j-1];
	    x[j-1] = temp; 
	    j = j-1;
	}
        i = i+1;
    }
    for(i = 0; i < size; i++)
	printf("%d\n", x[i]);
}

void insertionSortDescending(int* x, int(*comp)(const void* a, const void* b), int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while(i < size){
	j = i;
	while((j>0)&&(x[j-1]<x[j])){
	    temp = x[j];
	    x[j] = x[j-1];
	    x[j-1] = temp;
	    j = j-1;	    
	}
	i = i+1;
    }
    for(i = 0; i < size; i++) {
	printf("%d\n", x[i]);	
    }
}
void insertionSortEven(int* x, int(*comp)(const void*a, const void* b), int size)
{
    int* aEven = (int*)malloc(sizeof(int));
    int* aOdd = (int*)malloc(sizeof(int));
    int i = 0;
    int counter = 0;
    int counter2 = 0;
    int j = 0;
    int temp = 0;
    int temp2 = 0;
   
    for(i = 0; i < size; i++) {
	if((x[i]%2) == 0){
	    aEven[counter] = x[i];
	    aEven = (int*)realloc(aEven, sizeof(int));
	    counter++;
	}
    }
    for(i = 0; i < size; i++) {
	if((x[i]%2) == 1) {
	    aOdd[counter2] = x[i];
	    aOdd = (int*)realloc(aOdd, sizeof(int));
	    counter2++;
	}
    }
    i = 0;
    j = 0;
    while(i < counter) {
	j = i;
	while((j > 0) && (aEven[j-1]>aEven[j])){
	    temp = aEven[j-1];
	    aEven[j-1] = aEven[j];
	    aEven[j] = temp;
	    j = j-1;	     
        }
	i = i+1;
    }
    i = 0;      
    j = 0;
    while(i < counter2) {
	j = i;
	while((j > 0)&&(aOdd[j-1]>aOdd[j])){
	    temp2 = aOdd[j-1];
	    aOdd[j-1] = aOdd[j];
	    aOdd[j] = temp2;
	    j = j-1;
	}
	i = i+1;
    }
    for(i = 0; i < counter; i++){
	printf("%d\n", aEven[i]);
    }
    for(i = 0; i < counter2; i++){
	printf("%d\n", aOdd[i]);
    }
} 
int compare(const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    if(*x > *y) {
	return 1;
    }
    if(*x < *y) {
	return -1;
    }
    else {
	return 0;
    }

}

int main()
{
    int* arr = NULL;  
    int size = 0;
    char choice[1] = "\0"; 
    int i = 0;
    while(1 == 1){
    printf("How many integers would you like enter?\n");
    fscanf(stdin, "%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("Now enter %d numbers\n", size);
    while(i < size) {
	fscanf(stdin, "%d", &arr[i]);
	i++;
    }
  
    printf("Enter the number of the choice you wish to use\n");
    printf("1. BubbleSort (Increasing)\n");
    printf("2. BubbleSort (Decreasing)\n");
    printf("3. BubbleSort (Increasing - even before odd)\n");
    printf("4. InsertionSort (Increasing)\n");
    printf("5. InsertionSort (Decreasing)\n");
    printf("6. InsertionSort (Increasing - even before odd)\n");
    fscanf(stdin, "%s", choice);
    size = i;
    if(strncmp(choice, "1", 1) == 0){
	sort(choice, bubbleSortAscending, arr, size, compare);
	return 0;
    }
    else if(strncmp(choice, "2", 1) == 0){
	sort(choice, bubbleSortDescending, arr, size, compare);
	return 0;
    }
    else if(strncmp(choice, "3", 1)==0){
	sort(choice, bubbleSortEven, arr, size, compare);
	return 0;
    }
    else if(strncmp(choice, "4", 1) == 0) {
	sort(choice, insertionSortAscending, arr, size, compare);
	return 0;
    }
    else if(strncmp(choice, "5", 1) == 0) {
	sort(choice, insertionSortDescending, arr, size, compare);
	return 0;
    }
    else if(strncmp(choice, "6", 1)==0) {
	sort(choice, insertionSortEven, arr, size, compare);
	return 0;
    }  
    else {
	printf("Error entering choice\n");
    } 
    }
    return 0;
}
