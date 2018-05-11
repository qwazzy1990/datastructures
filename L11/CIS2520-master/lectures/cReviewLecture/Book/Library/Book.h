#ifndef BOOK_H
#define BOOK_H

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
Book* createBook( char * title, double price );

/**
 * Get price of book
 * @param  b Book
 * @return   Double price
 */
double getPrice( Book * b ); 

/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book *b );

/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( void * v );

/**
 * Print the book in another order
 * @param b [description]
 */
void printBookReverse( Book * b );

/**
 * Comparison Function for 2 books by prices
 * @param  a Book
 * @param  b Book
 * @return   -1,0,1 for comparison
 */
int compareBooksByPrice( Book * a, Book *b );

/**
 * Comparison Function with function pointer
 * @param a           [description]
 * @param b           [description]
 * @param compareFunc function pointer
 */
void printComparison( Book * a, Book * b, CompareBooksFunc compareFunc );

#endif

