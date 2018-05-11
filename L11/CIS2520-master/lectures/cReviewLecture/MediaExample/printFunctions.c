#include "printFunctions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints integer data, does the same things as printIntType
 * but shows the steps for casting
 * @param data [description]
 */
void printIntSteps( void * data )
{
    // Cast void pointer to integer pointer
    int* intPtr = (int*)data;
    //Dereference the value
    int value = *intPtr;
    printf( "INTDATA %d\n", value );
}


void printIntType( void * data)
{
    // Same as printIntSteps but in 1 step
    printf( "INT MEDIA DATA %d\n", *((int*)data) );
}

void printDoubleType( void * data  )
{
    printf( "DOUBLE MEDIA DATA %f\n", *((double*) data ) );
}

void printDouble( double * data )
{
	printf( "DOUBLE Data %f\n", *data );
}
