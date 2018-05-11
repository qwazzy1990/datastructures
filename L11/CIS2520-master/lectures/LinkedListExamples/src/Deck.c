#include "Deck.h"

Deck* createDeck()
{
    Deck* deck = malloc(sizeof(Deck));
    deck->cards = NULL;
    
    return deck;
}

void initializeDefaults(Deck * deck)
{
    if( deck->cards == NULL )
    {
        // Create a LinkedList of Cards
        deck->cards = initializeList(&printCard,&deleteCard,&compareCards);

        // Creating a deck of cards
        int startValue = 1; // Ace
        int endValue = 13;  // King
        Suit s[4] = {Heart, Diamond, Spade, Club};
        int idx = 0;
        for( int i =0; i < 4; i++)
        {
            for( int y = startValue; y <= endValue; y++)
            {
                // Adding each card to the deck of cards.
                // Using addBack with deck and creating each card
                // with one of the suits and y-> a value between 1(Ace)
                // and 13(King)
               	insertBack(deck->cards, createCard(s[i], y ) );
                idx++;
            }
        }
    }
}
