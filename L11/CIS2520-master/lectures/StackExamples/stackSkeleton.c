#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The array version of a stack 
// It has dynamic size and it's not an ADT.
typedef struct stack
{
	int count;
	int size;
	char arr[15];
} Stack;

int getSize()
{
	// TODO:
}

int count()
{
	// TODO:
}

char pop()
{
	// TODO:
}

char top()
{
	// TODO:
}

void push(Stack* s, char ch)
{
	// TODO:
}

int main ( int argc, char ** argv )
{
	Stack * s = malloc(sizeof(Stack));	

	// Read in a string 
	//DO Stuff;

	free(s);
}


