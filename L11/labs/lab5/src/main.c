#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StackAPI.h"

void printFunc(void* toBePrinted) 
{
	// Cast a void pointer to an integer pointer
	int* i = (int*)toBePrinted;
	// deference integer pointer to get integer value.
	printf("%d ",*i);
}

void deleteFunc(void* toBeDelete) 
{
	// Because we're using integer pointers with insert data
	// We have to delete the data.
	// We cast it andt he free it.
	int* i = (int*)toBeDelete;
	free(i);
	i = NULL;
}

int compareFunc(const void* a, const void* b) 
{
	// First we cast our data to integer pointers
	// Then we can compare them
	int* ap = (int*)a;
	int* bp = (int*)b;

	// Checking the value of these to pointers
	if( *ap == *bp)
		return 0;

	return *ap < *bp;
}

int main( int argc, char ** argv)
{
	// Initialize our stack with the three functions
	Stack * s = initializeStack(printFunc,deleteFunc,compareFunc);
		
	// Create dynamic memory for our integers.
	// We've ben using static memory integers for this example we show
	// dynamic memory.
	int* itop = NULL; 

	// Integer N we're going to read in
	int* n = malloc(sizeof(int));

	// Read our integer 
	printf("Please input a number:\n");
	scanf("%d",n);

	// Read values until a negative number is input
	while( *n >= 0 ) {
		
		// While the stack is not empty 
		// While we could potentially 'squash' another value.
		// Keep Checking

		while( !isEmpty(s) ) 
		{
			// Get the top of the stack.
			itop = top(s);

			// Check if the top is smaller than input number
			if( *itop < *n ){
				// That value has been squashed remove it from the stack.
				printf("%d squashes %d\n", *n, *itop);
				pop(s);
			}
			else
				break;	// Can't squash anymore stop
		}

		// Notice: We're making a copy of the integer value before inserting it into our stack.
		// 		This is because we plan to reuse n. Without, creating a new memory space
		//		both the stack verion of n and the main version of 'n' would point to the same memory
		// 		location which would mean if one of them changes the other also changes.
		// SideNote: Your LinkedList could handle this 'copying' internally too.
		int* newN = malloc(sizeof(int));
		*newN = *n;
		push(s,newN);

		printf("Please input a number:\n");
		scanf("%d",n);
	}
	printf("Receive: ");
	// Notice I didn't write a wrapper to printStack
	// You can still use list functions if needed.

	printForward(s->list);
	deleteStack(s);
	free(n);
	return 0;
}
