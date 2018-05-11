#include <stdlib.h>
#include <stdio.h>
#include "Card.h"
#include "Deck.h"

/* 
 * This a 4 player card game where each player holds 1 card
 * There is a deck of cards for all 52 cards and a stack of played cards.
 * There is linkedList of players each taking turns 
 * The game at most lasts for 200 seconds
 * Each player gets 10 seconds per turn which usually means nothing
 * but everyt 3rd tean there is a break for 10 seconds.
 *
 * Players play only if they can play a higher card otherwise
 * They may swap cards with the top card in the deck.
 * Each time a player plays a card its for 1 point.
 * The player with the most points at the end of the game wins.

 * We use function pointers at the end of the game to demonstrate
 * the flexibility of multiple game scoring systems using the same 
 * function to calculate the score.
 */

int main( int argc, char **argv)
{
    // Deck of Cards
    Deck * deck = createDeck();
    initializeDefaults(deck);

    // Empty stack of cards for players to play on
    Deck* stack = createDeck();

    // Linked List of Players
    // Initializing a linkedList of players not each of these functions exists
    // in players.h
    LinkedList players = initializeList(&printPlayer,&deletePlayer,&comparePlayers);

    //Create players and load a single card for the player to use.
    loadFile("assets/cards.txt", players);

    // Game Simulation Loop
    int time = 0;
    int maxSimulationTime = 200;
    int timePerTurn = 10;

	// Created a new rule every 3rd turn the players need a break
	int index =0;
	int skipPlayerEvery3Turns =2; // zero based


    while(true)
    {
        // Indicate when the game has ended
		// If Time is greater than maxSimulation time we end the game
        if( time >= maxSimulationTime )
            break;

		// This rule takes a break for 10 seconds and then continues the game
		// continue will start the loop form the start
		// It adds the time for the turn to the total time; 
		if( index >= skipPlayerEvery3Turns)
		{
			time += timePerTurn; 
			index = 0;
        
			continue;
		}

        // Player 1 to take a turn
        Player* p = getFromFront(players);
		
		// Remove player from the front of the list and put them at the back of it later. 
		deleteNodeFromList(list,p);

        // Get the card on the top of card stack for comparison
        // to player's card.
        Card * onTopOfStack = getFromFront(stack->cards);
		// Remove from the top of the stack
		deleteNodeFromList(stack->cards, onTopOfStack);

        // If Player1 card is greater than stacks Cards
        // they can play that card for a point
        if( compareCards(onTopOfStack, p->card) == 1)
        {
            //add player's card  and  +1 to score
            insertFront(stack,p->card);
            p->score++;
            //Get new card
            setCard(p,getFromFront(deck));
        }
        else
        {
            // Player can take a card from the deck
            Card * newCard = getFromFront( deck );

            // Here we're using compareCards as normal
            // Rather than in a linkedList
            if( compareCards(p->card,newCard) ==  1)
                swap(p->card, newCard); //note this function doesn't exist
        }
        
        // Player's turn is over, put them back of the turns list
        insertBack(players, p);

        // Time increases to next player's turn
        time++;
    }

    // At this point the game is over
    // So we create some sort of scoring system.
    // Lets consider multiple methods of scoring
    
    // Method 1: Max Score wins
    int maxScore = 0;
    int maxId = 0;
    // Iterate over list and get players
    for(int i = 0; i < 4; i++ ) {
        Player *p = getFromFront(players);
        if(p->score > minScore )
        {
            maxScore = p->score;
            maxId = i;
        }
    }

    // Method 2: Team Score
    // Lets take advantage of function pointers    
	
	// These 3 functions are a number of different ways to score the game
    
    // Could be best individual score on a team
    displayBestTeamScore(players,&createBestscore);

    // Could be total cumulative score from two players
    displayBestTeamScore(players,&createScore);

    // Could be lowest total cumulative score from two players
    displayBestTeamScore(players,&createGolfScore);


    return 0;
}
