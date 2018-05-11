#ifndef SIMULATION_H
#define SIMULATION_H

#include "LinkedListAPI.h"
#include "Player.h"

int createScore(Player *a, Player* b);

int createGolfScore(Player *a, Player* b);

int createBestScore(Player *a, Player* b)


// This function takes two players from the list of 4 players
// It creates a team score based on the function pointer passed in.
void displayBestTeamScore(LinkedList* players, int (*createScores)(Player*,Player*) );
#endif
