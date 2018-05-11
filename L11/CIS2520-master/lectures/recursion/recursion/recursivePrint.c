#include<stdlib.h>
#include<stdio.h>

/*
 * Here is our recursive function to print a string backwards.
 * We could have done this many different ways.
 * This version print the current index and moves backwards until
 * it reaches the first position. Then it prints and returns.
 * We didn't use a return statement for index == 0 case.
 * When the case for index == 0 function ends it automatically calls previous
 * function
 */
void printReverse(int index, char* str) 
{
	if(index == 0)
	{
		printf("%c", str[index]);
	}
	else
	{
		printf("%c", str[index]);
		printReverse(index-1,str);
	}
}


/**
 * This version has the same result as previous function but now
 * print is only called after hitting our stopping point.
 * IE, once we start to recurse back to the top.
 */
void printReverse2( int index, int length, char * str)
{
	if( index >= length )
	{
		return;
	}
	else
	{
		printReverse2( index+1,length,str);
		printf("%c",str[index]);
	}
}

int main( int argc, char ** argv )
{
	// Select a string to print backwards. Starting a index 4.
	char * str = "hello";
	printReverse(4,str);
	
	printf("\n");
	// A second version that starts at index 
	printReverse2(0,5,str);
}
