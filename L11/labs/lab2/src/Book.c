#include "Book.h"
#include <stdlib.h>
#include <stdio.h>

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
char* getName( Book *b )
{
	return b->name;
}

/**
 * Display a book's name and price.
 * @param b [Book]
 */
//void printBook( Book * b ) 
void printBook( void* b ) 
{
    printf("%s : %f\n", getName(b), getPrice(b) );
}

/**
 * Print the book in another order
 * @param b [description]
 */
void printBookReverse( Book * b )
{
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

