#include <stdio.h>
#include <stdlib.h>

#include "media.h"
#include "printFunctions.h"


int main( int argc, char ** argv )
{
    // Lets create a library (array) of media 
    Media* myLibrary;
    myLibrary = (Media*)malloc(sizeof(Media)*10);

    // Lets Create two types of contrived media and insert the media into the library
    // Pretending that integer is a media type
    // See void can be anything so we have to be careful
    int val = 7;
    int * myPtr = &val;
    setMedia( &myLibrary[0], myPtr );

    // Pointer to type double
    double* dptr = malloc(sizeof(double));
    *dptr = 123.321;
    setMedia( &myLibrary[1], dptr);

    // What about getting our information back.
    // Printing using different function pointers
    printMedia( getMedia(&myLibrary[0]), printIntSteps);
    printMedia( getMedia(&myLibrary[0]), printIntType);
    printMedia( getMedia(&myLibrary[1]), printDoubleType);
	//printMedia( getMedia(&myLibrary[1]), printDouble);

    free(myLibrary);
    free(dptr);

    return 0;
}
