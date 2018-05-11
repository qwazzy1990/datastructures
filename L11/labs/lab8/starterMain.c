/**
 *
 * Starter file for Lab 8
 * Note: You may not change any of the parameters of the functions or typedefs.
 *		You may use a different printArray function if you wish.
 */ 

#include<stdio.h>

/**
 * Create a typedef for a  Compare Function 
 */
typedef int (*CompareFunc)(void* a, void* b);

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length )
{
	for(int i =0 ; i < length; i++ ) 
		printf("%d ", arr[i]);
	printf("\n");
}

/***
 * NOTE: You will implement this function, it will be used to call all sorting algorithms. 
 *      It will also output the all the information required by the output section of the lab.
 *       
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)


int main(int argc, char ** argv )
{
	return 0;
}
