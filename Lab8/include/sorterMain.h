#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSortAscending(int x[], int (*compare)(const void* a, const void* b), int size);
void bubbleSortDescending(int x[], int (*compare)(const void* a, const void* b), int size);
void bubbleSortEven(int x[], int (*compare)(const void* a, const void* b), int size);
void insertionSortAscending(int*x, int (*compare)(const void*a, const void* b), int size);
void insertionSortDescedning(int* x, int (*compare)(const void* a, const void* b), int size);
void insertioSortEven(int* x, int (*compare)(const void* a, const void* b), int size);
void sort(char* menuSelection, void (*s)(int x[], int (*compare)(const void* a, const void*
b), int z), int* array, int length, int comp(const void* a, const void* b));
int compare(const void* a, const void* b);
