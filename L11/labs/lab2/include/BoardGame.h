#ifndef BoardGame_H
#define BoardGame_H

typedef struct BoardGame {
    double price;
    char *name;
    char* brand;
} BoardGame;

// Typedef for the function pointer
typedef void (*PrintBoardGameFunc)(BoardGame*);
typedef int (*CompareBoardGamesFunc) (BoardGame*,BoardGame*);


/**
 * [createBoardGame description]
 * @param  title static string of title
 * @param  price double
 * @return       a dynamically created BoardGame.
 */
BoardGame* createBoardGame( char * title, double price, char* brand );

/**
 * Get price of BoardGame
 * @param  b BoardGame
 * @return   Double price
 */
double getBoardGamePrice( BoardGame * b ); 

/**
 * Return a BoardGames name
 * @param  b BoardGame
 * @return   char* string of name
 */
char* getBoardGameName( BoardGame *b );

/**
 * Return a BoardGames name
 * @param  b BoardGame
 * @return   char* string of name
 */
char* getBoardGameBrand( BoardGame *b );

/**
 * Display a BoardGame's name and price.
 * @param b [BoardGame]
 */
 // Original API
//void printBoardGame( BoardGame * b );
void printBoardGame( void * b);

/**
 * Print the BoardGame in another order
 * @param b [description]
 */
void printBoardGameReverse( BoardGame * b );

/**
 * Comparison Function for 2 BoardGames by prices
 * @param  a BoardGame
 * @param  b BoardGame
 * @return   -1,0,1 for comparison
 */
int compareBoardGamesByPrice( BoardGame * a, BoardGame *b );

/**
 * Comparison Function with function pointer
 * @param a           [description]
 * @param b           [description]
 * @param compareFunc function pointer
 */
void printBoardGameComparison( BoardGame * a, BoardGame * b, CompareBoardGamesFunc compareFunc );

#endif

