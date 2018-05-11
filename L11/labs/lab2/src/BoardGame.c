#include "BoardGame.h"
#include <stdlib.h>
#include <stdio.h>

BoardGame* createBoardGame( char * title, double price, char* brand )
{
    BoardGame* b = malloc(sizeof(BoardGame));
    b->price  = price;
    b->name = title;
    b->brand = brand;
    return b;
}

/**
 * Get price of BoardGame
 * @param  b BoardGame
 * @return   Double price
 */
double getBoardGamePrice( BoardGame * b ) 
{ 
    return b->price;
}

/**
 * Return a BoardGames name
 * @param  b BoardGame
 * @return   char* string of name
 */
char* getBoardGameName( BoardGame *b )
{
    return b->name;
}

/**
 * Return a BoardGames name
 * @param  b BoardGame
 * @return   char* string of name
 */
char* getBoardGameBrand( BoardGame *b )
{
    return b->brand;
}

/**
 * Display a BoardGame's name and price.
 * @param b [BoardGame]
 */
//void printBoardGame( BoardGame * b ) 
void printBoardGame( void* b ) 
{
    printf("%s\t%f\t%s\n", getBoardGameName(b), getBoardGamePrice(b), getBoardGameBrand(b) );
}

/**
 * Print the BoardGame in another order
 * @param b [description]
 */
void printBoardGameReverse( BoardGame * b )
{
    printf("%f : %s\n", getBoardGamePrice(b), getBoardGameName(b));
}

/**
 * Comparison Function for 2 BoardGames by prices
 * @param  a BoardGame
 * @param  b BoardGame
 * @return   -1,0,1 for comparison
 */
int compareBoardGamesByPrice( BoardGame * a, BoardGame *b )
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
void printBoardGameComparison( BoardGame * a, BoardGame * b, CompareBoardGamesFunc compareFunc )
{
    int result = compareFunc(a,b);

    if( result == 0 )
        printf("BoardGames are the same\n");
    else if(result == -1)
        printf("The first BoardGame is less\n");
    else
        printf("The second BoardGame is less\n");
}