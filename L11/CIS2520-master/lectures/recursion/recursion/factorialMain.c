#include<stdio.h>
#include<stdlib.h>

// The Iterative approach
int factNumber( unsigned int count )
{
	int fact = 1;
	printf("Iterative Factorial for %d\n", count);
	for(int i = 1; i <= count; i++)
	{
		printf("Current value of factorial %d\n", fact);
		fact *= i;
	}
	return fact;
}

// Recursive approach
int factNumberRecursive( unsigned int count )
{
	// Base case, we always need a stopping condition
	// Here, we stop when the number 1 is reached.
	printf("Recursive Factorial solving for %d\n", count);
	if( count  == 0 )
		return 1;

	// This our recursive steps.
	// We break the problem down by subtracting - 1
	// The problem is smaller in temrs of having 1 less number
	// to multiply by.
	return count * factNumberRecursive(count-1);
}

// Recursive approach
int factNumberRecursiveUp( int current, unsigned int count )
{
	// Base case, we always need a stopping condition
	// Here, we stop when the number 1 is reached.
	printf("Recursive Factorial solving for %d\n",current);
	if( current  == count )
		return count;

	// This our recursive steps.
	// We break the problem down by subtracting - 1
	// The problem is smaller in temrs of having 1 less number
	// to multiply by.
	return current * factNumberRecursiveUp(current+1, count);
}

int main( int argc, char ** argv )
{
	int count = 0;

	printf("Please input a number > 0\n");
	scanf("%d",&count);
	while(count >= 0 )
	{
		// Start the recursive function call
		int result = factNumberRecursiveUp(1, count );
		//int result = factNumber( count );
		printf("The sum is %d\n", result );
		
		printf("Please input a number > 0\n");
		scanf("%d",&count);
	}
}
