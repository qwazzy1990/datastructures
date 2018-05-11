#include <stdlib.h>
#include <stdio.h>
#include "Store.h"
#include "Book.h"
#include "BoardGame.h"

// Typedef for alternative 
typedef void (*VoidFunc)(void*);

int main( int argc, char ** argv) 
{
	// Create our two books
	Book * a  = createBook("Lord of the Rings", 10.99); 
	Book* b = createBook("Hello again", 11.99);

	// Create one store
	Store * s = malloc(sizeof(Store));

	// Method suggested to class 'Please Read Error'
	// Set our function pointer
	setPrintType(s,&printBook);
	
	// Note: This is the alternative method 
	// Where you could cast the printFunction into a format needed
	// Instead, of changing printBook( Book* a) into printBook(void*a);
	// Alternative, method  casting printBook
	// Requires changing Book.h printBook back to original API
	//setPrintType( s, (VoidFunc)&printBook);

	// Set our first book
	setItem(s,b);

	// Display what is in the store
	displayStore(s);

	// Set our second book;
	// Replace the original Book with a different book.
	setItem(s,a);

	// Display what is in the store
	displayStore(s);

	free(b);
	free(a);

	// End of the BOOK SECTION
	// 
	// Create our two books
	BoardGame * ba  = createBoardGame("Lord of the Rings Monopoly", 10.99, "Matel"); 
	BoardGame* bb = createBoardGame("Pandemic", 51.99, "Lost World");

	setPrintType(s,&printBoardGame);
	setItem(s,ba);
	displayStore(s);
	setItem(s,bb);
	displayStore(s);

	// Free
	free(ba);
	free(bb);
	free(s);
}

