// Standard Libraries
#include <stdlib.h>
#include <stdio.h>
#include "Book.h"


/**
 * Example only put structs and in their own file away from main.
 */

/**
 * A struct that holds void data or any data
 */
typedef struct viewer
{   
    void * data;
} Reader;

/**
 * setReaderInterest in any type of data
 * @param reader void*
 * @param data   void*
 */
void setReaderInterest( Reader * reader, void * data )
{
    // Since void doesn't care we can just assign
    reader->data = data;
}

void printReaderInterest( Reader * reader )
{
    // Here we must cast it back to a type before using it.
    Book* book = (Book*)reader->data;
    printBook(book);
}

int main(int argc, char ** argv)
{
    // name these better in your code.
    Book * a = createBook("Lord of the Rings", 17.99);
    Book * b = createBook("Harry Potter And The Cursed Child", 19.99);

    printf("The library currently holds the following books:\n");

    printBook((void *) a);
    printBook((void *) b);
    
    printf("\n\nThe reader is currently interested in:\n");

    Reader *reader = malloc( sizeof(Reader) );
    setReaderInterest(reader, a);
    printReaderInterest(reader);


    printf("Reader has switched interests.\n");
    setReaderInterest(reader, b);
    printReaderInterest(reader);

    free(b);
    free(a);
    free(reader);
    return 0;
}

