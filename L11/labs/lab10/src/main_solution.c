#include<stdlib.h>
#include<stdio.h> 
#include "LinkedListAPI.h"

/** 
 * UserFunctions for the list
 */
void printData( void* data )
{
	int* i = (int*)data;
	printf("%d ", *i);
}

void deleteData( void* first)
{
	//EMPTY Function
}


int compareData( const void* first, const void* second)
{
	// Not Needed
	return 0;
}


/**
 * Check if a word is palindrome.
 * A Palindrome is a word/phrase spelt the same forward and backwards.
 * The logic is check if first and last characters are equal, ie a[0] and a[length-1].
 * While that is true move forward toward the middle of the string from both ends.
 * a[1] == a[length-2], a[2] == a[length-3]
 */
 // This is the first recursion problem 
int isPalindrome(char * str, int length)
{
	// If the length is 1 or < we know we have a palindrome // Because 'a' or '' is a palindrome. 
	if( length <= 1)
		return 1;
	
	// Check first and last character are equal.
	if( str[0] == str[length-1]){
		// We've checked the first and last characters so move
		// To next character +1
		// Decrease the length of string by -2 to remove the
		// the 2 characters just checked  by if statement.
		return isPalindrome(str+1,length-2);
	}
	return 0;
}


/**
 * Recursive function designed by you. 
 * This function recursively calls itself and counts the number of occurents of a target integer value.
 */
int countOccurrences( Node * list, int target)
{
	// What is the stopping condition of this recursion
	if(list == NULL)
		return 0;
	
	// If not stopping what should be calculated here and how do you break this problem down.
	int n = *( (int*) list->data);
	if( n == target )
		return 1 + countOccurrences(list->next, target);
	return countOccurrences(list->next, target);
}

/**
 *	Designed by you.
 *  This function prints the values of a list in order of occurrences. If the current element in the list is equal to a preselected target value (choosen by you).
 *  The list skips head target times then continues printing. Skipping includes the target value.
 *  Node* list -> is the current position in the list.
 *  target -> is the preselected value that initiates the skip and the number of items to skip.
 *  skipCount -> Starts as 0 but is used to countDown the number of items to skip remaining before print again. 
 *  ex)  list = [1 3, 4, 5, 6, 8]
         target = 3

		 prints-> 1 6 8 
 */

void printSkipList( Node * list, int target, int skipCount )
{
	// What is the stopping condition of this recursion
	
	// If not stopping what should be calculated here and how do you break this problem down.
	if( list == NULL )
		return;

	if( skipCount > 0 )
	{
		printSkipList( list->next, target, skipCount -1 );
		return;
	}
		
	int n = *( (int*) list->data);
	if( n == target )
		printSkipList( list->next, target, n-1 );
	else
	{	
		printf("%d ", n );
		printSkipList( list->next, target, 0);
	}
}



/**
 * Advanced: Recursion
 *  		Check if a List contains integer that sum to a value
 			This recursive function searches through each possible branches.
			Consider this an all 'possible' combinations of the values in the list.	
 */

 int sumToTarget( Node * list, int currentSum, int targetSum )
 {
	printf("Current sum is %d\n", currentSum);
	// If we've summed to the correct target end.
 	if( currentSum == targetSum )
		return targetSum;
	
	/* 
     * This section start numerous recursive calls.
	 * It will recurse for each remaining number in the list 
	 * if that value + current sum is < target value.
	 * Note: that each recursive call starts a branch of further calls.
	 * ie for 1 3 5 these trees will be checked
	 								1 3 5
	                      1				3			5
					3         5		5		
				5

	 */
	Node * currentHead =list;
	while( currentHead != NULL )
	{
		// Get the current value at from of the list
		int n = *( (int*) currentHead->data);
		// If that value + current sum is less than target
		// We can add that value to our sum and check the rest of the list.
		if( currentSum + n <= targetSum )
		{
			// This checks the rest of the list
			// Move our node position forward 1
			// Add currentSum plus the head of the list
			int result =  sumToTarget(currentHead->next, currentSum+n, targetSum);
			// If we got a good result return it
			// Otherwise, we have to check other lists.
			if( result ==  targetSum)
				return targetSum;
		}
		currentHead = currentHead->next;
	}
	return currentSum; 
 }

int main(int argc, char ** argv )
{
	int problem = 0;
	if( argc > 1)
		problem = atoi(argv[1]);

	if (problem == 1)
	{
		// Initialize your function here
		List * list = initializeList( &printData, &deleteData,&compareData);

		// A couple test cases.
		int values[] = { 1, 3, 5, 4, 3 ,6, 10 ,12, 1 };
		//int values[] = { 1, 10, 5 };
		//int values[] = { 1, 3, 6 };

		// Initialize list and print to display correctly setup.
		int sizeArr = sizeof(values)/sizeof(values[0]);
		for( int i = 0; i < sizeArr; i++)
			insertFront( list, &values[i] );

		printf("Starting with list:\n");
		printForward(list);
		printf("\n");

		int result = countOccurrences( list->head, 3); 
		printf("The result was %d\n", result);


	}
	else if( problem == 2 )
	{
		// Initialize your function here
		List * list = initializeList( &printData, &deleteData,&compareData);

		// A couple test cases.
		int values[] = { 1, 3, 5, 4, 3 ,6, 10 ,12, 1 };
		//int values[] = { 1, 10, 5 };
		//int values[] = { 1, 3, 6 };

		// Initialize list and print to display correctly setup.
		int sizeArr = sizeof(values)/sizeof(values[0]);
		for( int i = 0; i < sizeArr; i++)
			insertBack( list, &values[i] );

		printf("Starting with list:\n");
		printForward(list);
		printf("\n");

		printSkipList( list->head,5,0);
	}
	else if( problem == 3)
	{	
		/** 
		 * Here we test 2 different strings to see if they're palindromes.\n
		 */
		char str[] = "this is a test string that";
		char pstr[] = "madamimadam";

		// These check the size of the array against the size of the first character
		// Since the array uses all the same data type, arr[0] is the same size as all other elements.
		int strSize = sizeof(str)/sizeof(str[0]); 
		int pstrSize = sizeof(pstr)/sizeof(pstr[0]);

		if( isPalindrome(str,strSize-1) )
			printf("%s is palindrome\n",str);
		else 
			printf("%s is not a palindrome\n",str );

		
		if( isPalindrome(pstr,pstrSize-1) )
			printf("%s is palindrome\n",pstr);
		else 
			printf("%s is not a palindrome\n",pstr);
	}
	else
	{
		// Initialize our List, we're not really using any of these functions.
		List * list = initializeList( &printData, &deleteData,&compareData);

		// A couple test cases.
		int values[] = { 1, 3, 5 };
		//int values[] = { 1, 10, 5 }; //int values[] = { 1, 3, 6 }; 
		// Initialize list and print to display correctly setup.
		int sizeArr = sizeof(values)/sizeof(values[0]);
		for( int i = 0; i < sizeArr; i++)
			insertFront( list, &values[i] );

		printf("Starting with list:\n");
		printForward(list);
		printf("\n");
	
		// Setup a target to search for.
		int target =10;
		/*
		 * Here we pass the head of the list to start the search.
		 * The search will progessively use each node to search the whole list.
		 */
		if( sumToTarget(list->head, 0, target ) == target )
			printf("We can sum to %d value\n", target );
		else
			printf("Can't sum to target of %d\n", target);
	}
	
	return 0;
}
