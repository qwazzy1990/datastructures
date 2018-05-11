#include "Card.h"

Card* createCard( Suit s, int faceValue )
{
    Card * c = malloc(sizeof(Card));
    c->suit = s;
    c->value = faceValue;
    return c;
}

//  0 if Cards are the same
//  -1 if CardA is less than CardB
//  1 if CardB is less than CardA
int compareCards( Card * cardA, Card *cardB )
{
    // Just in case any of the cards are NULL
    if( cardB == NULL && cardA == NULL )
        return 0;
    if(cardB == NULL )
        return -1;
    if(cardA == NULL)
        return 1;

    // How we want to compare cards by face value
    if(cardA->value < cardB->value)
        return -1;
    else if(cardA->value == cardB->value)
        return 0;
    return 1;
}

void printCard( Card* c ) 
{
    if( c )
    {
        printf("CARD SUIT %c\n", c->suit);
        printf("CARD VALUE %d\n", c->value);
    }
}

void deleteCard( Card * d )
{
    // Intentionally blank
}
