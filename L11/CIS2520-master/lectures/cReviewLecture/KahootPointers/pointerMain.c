#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
	int c = 5, *pc;

	// Error: Pointer from an integer.
	//pc = c;

	// Compiles
	//pc = &c;

	//Fails
	//*pc = &c;  

	*pc = c;

	printf("%d\n", *pc);

	return 0;
}
