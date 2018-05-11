#include<stdio.h>
#include<stdlib.h>

/*
	These functions counts odd digits in a number
*/
// The Iterative approach
int countOdd( unsigned int number)
{
	int value = 0;
	while(number != 0)
	{
		printf("Counting odd numbers left in %d\n", number);
		int last = number % 10;
		printf("Last digit was %d\n\n", last);

		// Check if digit is odd and increment count if so.
		if( last%2 == 1 )
			value++;

		// move to the next digit.
		number /= 10;
	}
		
	return value;
}

// Recursive approach
int countOddRecursive( unsigned int number)
{
	printf("\nRecursive count Number %d\n", number);
	// Base case, we always need a stopping condition
	// Here, we stop when the number is 0 because it has no more 
	// digits to inspect 
	if( number  == 0 )
		return 0;

	// This our recursive steps.
	// We break the problem down check the last digit on the number
	// then dividing off the last digit
	// value will 0 when even
	// value will be 1 when odd
	int value = (number%10)%2;
	printf("Last digit was %d and it's value is %d\n\n",number%10,value);
	return value + countOddRecursive(number/10);
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
		int result = countOddRecursive( count );
		printf("The end result is %d\n", result );
		
		printf("Please input a number > 0\n");
		scanf("%d",&count);
	}
}
