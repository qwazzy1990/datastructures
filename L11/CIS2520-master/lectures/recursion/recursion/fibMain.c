#include<stdio.h>
#include<stdlib.h>

/*
	These functions calculate the fibonacci sequence for a specific indeq in sequence.
*/
// The Iterative approach
int fib( unsigned int number)
{
	// Store the first two sequence values
	int t1 = 0,t2 = 1;
	int term = 0;
	if( number == 0 )
		return t1;
	else if( number == 1 )
		return t2;
	

	// Iterate to generate other sequence values
	for(int i = 2; i <= number;i++)
	{
		term = t1 + t2;
		t1 = t2;
		t2 = term;
	}
		
	return term;
}

// Recursive approach
int fibR( unsigned int number)
{
	printf("\nRecursive Fib Number %d\n", number);
	// Base case, we always need a stopping condition
	// Here, we stop when the number is 0 or 1 because those numbers
	// are the first numbers used to generate the sequence.
	if( number  == 0 || number == 1 )
		return number;

	// This our recursive steps.
	// Now we have two recursive calls from one function
	// This is a branch, each time this code is run it creates two more calls
	return fibR(number-1) + fibR(number-2);
}

int main( int argc, char ** argv )
{
	int count = 0;

	printf("Please input a number > 0\n");
	scanf("%d",&count);
	while(count >= 0 )
	{
		printf("\n");
		// Start the recursive function call
		int result = fib( count );
		printf("The end result is %d\n", result );
		
		printf("Please input a number > 0\n");
		scanf("%d",&count);
	}
}
