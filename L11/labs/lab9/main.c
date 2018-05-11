#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * This function contains our basic % operator hash function.
 */
int hashFunc(int tableSize, int key) 
{
	// Lets use the division hash function
	// We aren't doing much to the key but it can be interesting to see
	// what the results from any hash function.
	return key%tableSize;
}

/*
 *	This function generates a set of phone numbers and stores them in an array.
 */
int* generateData( const int tableSize )
{
	int * array = malloc(sizeof(int)*tableSize);

	// Generate data
	// Here we select/generate data values that would be typical for our application.

	// Lets assume we're working phone numbers.
	// Phone numbers aren't great hash data because they can change frequently.
	
	// Setup our random number generator, this is only called once.
	// time(NULL) defaults to the current time but if you want your randomization to be consistent
	// between tests you could always change NULL to a specific value
	srand(time(NULL));

	// Fill up the array with data
	// Digits in our phone number
	int numDigits =7;
	int digit = 0, value =0, base = 1;
	for( int i = 0; i < tableSize; i++) 
	{
		// Generate a single phone number, 7 digit in this case;
		base = 1;
		value =0;
		for( int d = 0; d < numDigits; d++)
		{
			// Make sure the digit is between 1-9, note we're purposely ignoring 0 since 
			// phone numbers should be strings/arrays rather than integers.
			digit = rand()%9 + 1;

			// Now that we have a digit lets put it in the correct column
			// value is our phone number it's have digits added to it. 
			// base is the current column ie ones, tends, hundreds, thousands ...etc
			// Example 348 = 8*1 + 4*10 + 3*100
			value += (digit*base);
			base *= 10; 
		}		
		printf("Generated the number %d\n", value);
		array[i] = value;
	}
	return array;
}

int main( int argc, char ** argv )
{
	// Initialize our variables
	const int TABLE_SIZE = 100;
	int * data = generateData( TABLE_SIZE );
	int * table = malloc(sizeof(int)*TABLE_SIZE);

	int i = 0;
	// Initialize all values in table to 0
	for( i = 0; i < TABLE_SIZE;i++)
		table[i] = 0;
	
	int index = 0;
	// Counting the indices produced by our hash function
	for( i = 0; i < TABLE_SIZE;i++)
	{
		index = hashFunc(TABLE_SIZE,data[i]);
		table[index]++;
	}

	// Lets write our results to a file.
	FILE * file = fopen("results.txt","w");
	if(file)
	{
		// Lets make printable result for an excel type program.
		// count is a sanity check to make sure all (key,index)
		// are inside the table.
		int count = 0;
		fprintf(file,"Index:\tValue:\n");
		for( i = 0; i < TABLE_SIZE; i++)
		{
			fprintf(file,"%d", i);
			fprintf(file,"\t%d", table[i]);
			fprintf(file,"\n");
			count += table[i];
		}
		fprintf(file,"\n");

		printf("Found key and index pairs %d\n",count);
	}
	fclose(file);
}
