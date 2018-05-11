#include "Simulation.h"

int createScore(Player *a, Player* b)
{
    return a->value + b->value;
}

int createGolfScore(Player *a, Player* b)
{
    return -1*createScore(a,b);
}

int createBestScore(Player *a, Player* b)
{
    return max(a->value,b->value);
}


// This function takes two players from the list of 4 players
// It creates a team score based on the function pointer passed in.

void displayBestTeamScore(LinkedList* players, int (*createScores)(Player*,Player*) )
{
    // Team A
	// Created by taking the first and last players
    Player *a = getFront(players);
    Player *b = getBack(players);
    int teamAScore = createScores(a,b);

	// Remove the first player and put them at the back
	// To making getting the other two players easier
	deleteNodeFromList(list,a);
	insertBack(list,a);


    //Team B
	// Now the first two players in the list
    Player *c = getFront(players);
    Player *d = getFront(players);

	// Use the same function  to create a score for those players
    int teamBScore = createScores(c,d);

	// This is acomparison function we
    if(teamAScore == teamBScore)
        print("Tie game";
    else if(teamAScore < teamBScore)
        printf("Team B wins");
    else	
		printf("Team A wins");
}
