#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "LinkedList.h"

/**
 * Create a deck of cards. Deck is essentially a linkedList
 * We have one function to initialize with 52 cards.
 */
typedef struct deck
{
    LinkedList cards;
} Deck;

/**
 * Create an empty deck, cards is set to NULL
 * @return [description]
 */
Deck * createDeck();

/**
 * Cards is initialized with a default deck of cards.
 * @param deck [description]
 */
void initializeDefaults(Deck * deck);

#endif
