#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

/**
 * Create a player, player as a card and a score
 */
typedef struct player
{
    int score;
    Card * card;

} Player;

/**
 * Malloc space for a player and set Card
 * @param  c [description]
 * @return   [description]
 */
Player* createPlayer( Card* c );

/**
 * Mutators for Player's Card
 * @param p [description]
 * @param c [description]
 */
void setCard(Player* p, Card* c );

/**
 * Assessors for player's cards
 * @param p [description]
 * @param c [description]
 */
Card* getCard(Player* p);

/** Functions required to initialize a LinkedList of Players */
/**
 * Display a player
 * @param p [description]
 */
void printPlayer(Player* p);
/**
 * Delete player's card
 * @param p [description]
 */
void deletePlayer(Player* p);

/**
 * Compare two players by score.
 * @param  a [description]
 * @param  b [description]
 * @return   [description]
 */
int comparePlayers(Player* a, Player* b);

#endif
