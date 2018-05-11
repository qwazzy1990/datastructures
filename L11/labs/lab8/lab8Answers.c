/**
 * Starter file for Lab 8
 * Note: You may not change any of the parameters of the functions or typedefs.
 *		You may use a different printArray function if you wish.
 */ 

#include<stdio.h>
#include<stdlib.h>

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

/**
 * Bubble Sort
 */
void bubbleSort( int* array, int length, CompareFunc compare )
{
	int swap;
	for(int i =0; i < length; i++ ) {
		for(int y = 0;y < length-1;y++){
			// Comparison of 1 indicates a change needs to occur
			// Bubble sort moves items gradually to the end of the container by default
			if(compare( &array[y], &array[y+1]) == 1 ) 
			{
				swap = array[y];
				array[y] = array[y+1];
				array[y+1] = swap;
			}
		}
	}
}

/**
 * Selection Sort
 */
void selectionSort( int * array, int length, CompareFunc compare)
{
	int swap;
	int index;
	for(int i =0; i < length; i++ ) {
		swap = array[i];
		index = i;
		for(int y = i;y < length;y++){
			// Comparison of-1 indicates change 
			// because selection sort moves items to the left 
			if(compare(&array[y],&swap) == -1)  
			{
				swap = array[y];
				index = y;
			}
		}

		// Swap the two values
		array[index] = array[i];
		array[i] = swap;
	}
}

// Compare integers in increasing order.
int increasingOrder( void* a, void* b) {
	int * ai = (int*)a;
	int * bi = (int*)b;

	if( *ai == *bi)
		return 0;
	else if( *ai < *bi)
		return -1;
	return 1;
}

// Compare integers in decreasing order.
int decreasingOrder( void* a, void* b) 
{
	// Increasing is the opposite of decreasing.
	// So if we swap 1 and -1 values we should get
	// the correct answer.
	return (increasingOrder(a,b)*-1);
}

/**
 *
 * This was our tricky comparison function
 * If both numbers are odd or both even
 * We use our increasing Order operator (or another if statement)
 * When we have odd/even or even/odd numbers we return
 * -1 if even if first number 
 * 1 if even is second number
 * This puts priority to evens over odds
 */
int evenFirst( void* a, void * b)
{
	int * ai = (int*)a;
	int * bi = (int*)b;

	if( *ai % 2 == 0 && *bi % 2 != 0)
		return -1;

	if( *ai % 2 != 0 && *bi % 2 == 0)
		return 1;

	return increasingOrder(a,b);
}

/**
 * Display our results of our menu selections. 
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)
{
	printf("\nInitial Array:");
	printArray(array,length);
	printf("%s\n", menuSelection);
	sorter(array, length, compare);
	printf("Result Array:");
	printArray(array,length);
}

/**
 * printMenu options
 */
void printMenu()
{
	printf("Sorting Menu System\n");
	printf("1)	BubbleSort ( increasing order)\n");
	printf("2)	BubbleSort ( decreasing order )\n");
	printf("3)	BubbleSort ( increasing order – evens numbers before odd numbers )\n");
	printf("4)	SelectionSort ( increasing order)\n");
	printf("5)	SelectionSort ( decreasing order )\n");
	printf("6)	SelectionSort ( increasing order – evens numbers before odd numbers )\n");
	printf("7)	Quit\n");
	printf("Please enter a menu selection: ");
}

int main(int argc, char ** argv )
{
	int arrSize = 1;
	int menuChoice;

	// print Menu Choice
	printMenu();
	scanf("%d", &menuChoice);
	while( menuChoice >= 1 && menuChoice != 7)
	{
		// Read in the values from the command line.
		printf("Please enter the size of the array: "); 
		scanf("%d", &arrSize);

		// Read in Array could use dynamic memory here too.
		int array[arrSize];
		printf("Please enter %d values for the array: ",arrSize);
		for(int i = 0; i < arrSize; i++)
			scanf("%d", &(array[i]));

		// The menu Choices
		if( menuChoice  == 1 )
		{
			sort("BubbleSort ( increasing )", &bubbleSort, array, arrSize, &increasingOrder );
		}
		else if( menuChoice  == 2 )
		{
			sort("BubbleSort ( decreasing )", &bubbleSort, array, arrSize, &decreasingOrder);
		}
		else if( menuChoice  == 3 )
		{
			sort("BubbleSort (increasing order – evens numbers before odd numbers )\n", &bubbleSort, array, arrSize, &evenFirst);
		}
		if( menuChoice  == 4 )
		{
			sort("Selection ( increasing )", &selectionSort, array, arrSize, &increasingOrder );
		}
		else if( menuChoice  == 5 )
		{
			sort("Selection ( decreasing )", &selectionSort, array, arrSize, &decreasingOrder);
		}
		else if( menuChoice  == 6 )
		{
			sort("Selection (increasing order – evens numbers before odd numbers )\n", &selectionSort, array, arrSize, &evenFirst);
		}
		else if( menuChoice == 7 )
		{
			continue;
		}

		printf("\n\n");
		printMenu();
		scanf("%d", &menuChoice);
	}
	printf("Program completed\n");
	return 0;
}
