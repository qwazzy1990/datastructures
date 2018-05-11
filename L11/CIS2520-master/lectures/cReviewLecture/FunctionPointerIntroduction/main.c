#include <stdio.h>
#include <stdlib.h>

// Typedef we can make things look nicer
typedef int* IntPtr;
typedef void (*PrintIntFunc)(int*);

/************ Standard print function *******************************/
/**
 * Example of a print function
 * @param i [description]
 */
void printInt( int* i )
{
    printf("%d\n", *i);
}

/**
 * Example print function that prints the number twice.
 * @param i2 [description]
 */
void printInt2( int* i2 )
{
    printf("%d %d\n", *i2, *i2 );
}
/*********************************************************************/


/**
 * Function accepts a function pointer and an interger to be printed
 * @param anInt      Pointer to an integer
 * @param aPrintFunc Function Pointer to print function.
 */
void printAnyInt( int * anInt, PrintIntFunc aPrintFunc)
{
    aPrintFunc(anInt);
}

int main( int argc, char ** argv )
{
    // Create some data to use
    int val = 7;
    int * myPtr = &val;

    // Function Pointers the basic C-Way

    // This is the declaration of an ugly function pointer, name intFunc
    // It takes a pointer to an integer.
    void (*intFunc)(int*);

    // Set the pointer to the address of printInt2 function
    intFunc = &printInt2;

    // Calling the function pointer
    intFunc(myPtr);

    printf("END FIRST SECTION\n\n");
    /************************************************************/

    // Use typedef version of the function pointer
    val++;

    PrintIntFunc p;
    p = &printInt;

    PrintIntFunc p2;
    p2 = &printInt2;

    // Calling function pointer.
    p(myPtr);
    p2(myPtr);

    printf("END Second SECTION\n\n");
    /************************************************************/

    // Print using function pointer as a parameter
    val++;
    printAnyInt(myPtr, p );
    printAnyInt(myPtr, p2);
    printf("END of last SECTION\n\n");

    return 0;
}

