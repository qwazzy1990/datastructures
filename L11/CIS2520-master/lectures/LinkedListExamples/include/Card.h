#ifndef CARD_H
#define CARD_H

#include<stdlib.h>

/* You can use typedefs to improve readability.
    Here I'm creating four suits names and 
    indicating that they refer to specific 'characters'
*/
typedef enum suit { 
    Diamond = 'd', 
    Spade = 's', 
    Heart = 'h', 
    Club = 'c'
} Suit;

/**
 * Building our Card Structures
 */
typedef struct card {
    Suit suit;
    int value;
} Card;

/**
 * Create a card with suit and value
 * @param  s         [description]
 * @param  faceValue [description]
 * @return           [description]
 */
Card* createCard( Suit s, int faceValue );

/***************** Functions needed to initialize a list********/
/**
 * Print a card
 * @param c [description]
 */
void printCard( Card* c );

/**
 * Delete contents of card. Nothing done because card is static variables.
 * @param d [description]
 */
void deleteCard( Card * d );

/**
 * Compare two cards by their face value.
 * @param  cardA [description]
 * @param  cardB [description]
 * @return       [description]
 */
int compareCards( Card * cardA, Card *cardB );

#endif
