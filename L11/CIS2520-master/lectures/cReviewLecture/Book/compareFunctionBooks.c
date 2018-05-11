// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your structs and related functions shouldn't live in the main
// This is just an example for in-class


/**
 * Stores basic book information.
 */
typedef struct book {
    double price;
    char *name;
} Book;

// Typedef for the function pointer
typedef void (*PrintBookFunc)(void*);
typedef int (*CompareBooksFunc) (Book*,Book*);


/**
 * [createBook description]
 * @param  title static string of title
 * @param  price double
 * @return       a dynamically created Book.
 */
Book* createBook( char * title, double price )
{
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

/**
 * Get price of book
 * @param  b Book
 * @return   Double price
 */
double getPrice( Book * b ) 
{ 
    return b->price;
}

/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book * b )
{
	return b->name;
}

/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( void * v )
{
    Book * b = (Book *) v;
    printf("%s : %f\n", getName(b), getPrice(b) );
}

/**
 * Print the book in another order
 * @param b [description]
 */
void printBookReverse( void * v )
{
    Book * b = (Book *) v;
    printf("%f : %s\n", getPrice(b), getName(b));
}

/**
 * Comparison Function for 2 books by prices
 * @param  a Book
 * @param  b Book
 * @return   -1,0,1 for comparison
 */
int compareBooksByPrice( Book * a, Book *b )
{
    if( a->price == b->price )
        return 0;
    return a->price < b->price ? -1 : 1;
}

/**
 * Comparison Function with function pointer
 * @param a           [description]
 * @param b           [description]
 * @param compareFunc function pointer
 */
void printComparison( Book * a, Book * b, CompareBooksFunc compareFunc )
{
    int result = compareFunc(a,b);

    if( result == 0 )
        printf("Books are the same\n");
    else if(result == -1)
        printf("The first book is less\n");
    else
        printf("The second book is less\n");
}


int main(int argc, char ** argv)
{
    Book * a = createBook("Lord of the Rings", 17.99);
    Book * b = createBook( "Harry Potter And The Cursed Child", 19.99);

    PrintBookFunc display = &printBook;
    display((void *) b);

    printf("Prices of books are:\n");
    display = &printBookReverse;
    display((void *) a);
    display((void *) b);

    printComparison(a,b, compareBooksByPrice);
    
    free(b);
    return 0;
}

