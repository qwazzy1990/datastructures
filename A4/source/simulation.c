
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "simulation.h"
#include "BinSearchTreeAPI.h"
#include "Rule.h"
#include "ReadFile.h"
#include <ctype.h>


void runSim(Tree* theTree)
{
    char choice[10] = "\0";
    int error = 0;
    char newRating[100] = "\0";
    char haveConversation[100] = "\0";
    char newKeyWord[100] = "\0";
    char newResponse[100] = "\0";
    char deleteRule[100] = "\0";
    printf("Hello, welcome, my name is Elexa\n\n");
    while(1 == 1){
        if(error != 1){
    	    printf("Enter 1 to give me a new rule\n");
     	    printf("Enter 2 to remove one of my rules\n");
   	    printf("Enter 3 to display my rules\n");
   	    printf("Enter 4 to change the rating of one of my rules\n");
    	    printf("Enter 5 to have a conversation with me\n");
    	    printf("Enter 6 to say bye\n");
    	    fgets(choice, 10, stdin);
	}
        if(choice[0]=='1'){
	    printf("What new rule would you like to give me?\n");
	    printf("You must give me a word and a response\n");
	    printf("First the word\n");
	    fgets(newKeyWord, 100, stdin);
	    removeHardReturn(newKeyWord);
	    printf("Now the response\n");
	    fgets(newResponse, 100, stdin);
	    addToTree(theTree, createRule(newKeyWord, newResponse));
	    error = 0;  	   
	}
	else if(choice[0] == '2'){
	   printf("What rule would you like to get rid of?\n");
	   printInOrder(theTree);
	   printf("\n\n");
	   fgets(deleteRule, 100, stdin);
	   removeHardReturn(deleteRule);
	   deleteFromTree(theTree, theTree->root, deleteRule);
	  // printf("Oh no, please not that rule. I just love it so much I could not");
	  // printf(" bare to part with it\n"); 
	   error = 0;
	}
	else if(choice[0]=='3'){
            printf("IN-ORDER\n\n");
	    printInOrder(theTree);
	    printf("\n\n");
	    printf("PRE-ORDER\n\n");
	    printPreOrder(theTree);
	    printf("\n\n");
	    printf("POST-ORDER\n\n");
	    printPostOrder(theTree);
	    printf("\n\n");
	    error = 0;
	}
        else if(choice[0]== '4'){
	    printPreOrder(theTree);
	    printf("\n\n");
	    printf("What rule would you like to update?\n");
	    fgets(newRating, 100, stdin);
	    removeHardReturn(newRating);
	    updateUserRating(newRating, theTree);
	    error = 0;	   
	}
        else if(choice[0]=='5'){
             printf("What would you like to talk about?\n");
	     fgets(haveConversation, 1000, stdin);
	     removeHardReturn(haveConversation);	    
	     response(haveConversation, theTree);
	     error = 0;	    
	}
        else if(choice[0]=='6'){
	    printf("Nice meeting you, good bye\n");
	    return;
	    error = 0;
	}
	else {
	    printf("I don't understand what you want\n");
	    printf("Please enter 1, 2, 3, 4, 5, or 6\n");
	    fgets(choice, 100, stdin);
	    error = 1;
	}
    }


}


void response(char* x, Tree* theTree)
{
    char splitter[1000][1000];
    int i = 0; 
    int k = 0;
    int j = 0;
    int numberOfWords = 0;
    char buffer[100];
    Rule* arrayOfRules[100];
    for(i = 0; i < strlen(x); i++){
        if(x[i] != ' '){
	     splitter[k][j] = x[i]; 
	     j++;
	}
	else {
	    k++;
	    j = 0;
	}
    }
    void* temp = NULL;
    i = 0;
    j = 0;
    numberOfWords = k+1;
    while(i < numberOfWords){
	temp = findInTree(theTree, theTree->root, splitter[i]);
	if(temp != NULL){
	   arrayOfRules[j] = createRule2(temp);
	   j++;
	}
	i++;
    }
    for(i = 0; i < j; i++){
	for(k = 0; k < j-1; k++){
	    if(arrayOfRules[i]->systemRating < arrayOfRules[k]->systemRating){
		double newRating = arrayOfRules[k]->systemRating;
	        arrayOfRules[k]->systemRating = arrayOfRules[i]->systemRating;
	        arrayOfRules[i]->systemRating = newRating;
	    }
	}
    }
    printResponse(arrayOfRules[0]); 
    void* temp2 = findInTree(theTree, theTree->root, arrayOfRules[0]->keyWord);
    printf("Was that helpfulf? Enter y for yes or n for no\n");
    fgets(buffer, 100, stdin);
    removeHardReturn(buffer);
    updateRule(temp2, buffer[0]);   
}

void updateUserRating(char* a, Tree* theTree)
{
   void* temp = NULL;
   temp = findInTree(theTree, theTree->root, a);
   printRule(temp);
   printf("\n");
   char buffer[100] = "\0";
   printf("Enter the new user rating for this rule\n");
   fgets(buffer, 100, stdin);
   double newRating = atof(buffer);
   if(temp != NULL){
	if(0<= newRating && newRating <= 1){
           updateUserRate(temp, newRating);
	   printf("\n");
	   printf("\n");
       }
       else {
	   printf("Enter a number between 0 and 1 inclusively\n");
       }
   }
   else {
	printf("Sorry, that rule doesn't exist\n");
   }
}
