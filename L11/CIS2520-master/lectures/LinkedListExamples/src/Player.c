#include "Player.h"

Player* createPlayer( Card * c )
{ 
    Player* p = malloc(sizeof(Player));
    p->score = 0;
    p->card = c;
    return p;
}

void setCard(Player* p, Card* c )
{
    p->card =c;
}

Card* getCard(Player* p)
{
    return p->card;
}

void printPlayer(Player* p) 
{
    printf("Player:\n");
    printCard(p->card);
    printf("Score:%d",p->score;)
}
void deletePlayer(Player* p) 
{
    if( d->card != NULL)
    {
        free(d->card);
        d->card = NULL;
    }
}

int comparePlayers(Player* a, Player* b) 
{
    if( a->score == b->score )
        return 0;
    if(a->score < b->score)
        return 1;
    return -1;
}
