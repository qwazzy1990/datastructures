

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SimulationAPI.h"
#include "HashTableAPI.h"
#include "SinglyLinkedListAPI.h"
#include "FileInputAPI.h"
#include "WordAPI.h"

void runSim(HashTable* H)
{
    int i = 0;
    char choice[10] = "\0";
    char newWord[100][100];
    FILE* searchFile = NULL;
    char fileName[100] = "\0";
    int flag = 0;
    int k = 0;
    int flag2 = 0;
    int l = 0;
    int m = 0;
    int rightWords = 0;
    int wrongWords = 0;
    char searchWords[1000][100];
    char deleteWord[100][100];
    while(choice[0] != '5'){
	if(flag == 0){
    	    printf("1: Add a word to the dictionary\n");
    	    printf("2: Remove a word from the dictionary\n");
    	    printf("3: Spell check a file\n");
    	    printf("4: Show dictionary words\n");
    	    printf("5: Quit\n");
	    printf("Enter 1, 2, 3, 4 or 5\n");
    	    fscanf(stdin, "%s", choice);
        }
	if(choice[0] == '1'){
	    printf("Enter the name of the word you would like to add.\n");
	    fscanf(stdin, "%s", newWord[k]);
            insertDataInMap(H, newWord[k]);
	    flag = 0;
	    k++;
	}
	else if(choice[0] == '2'){
	   printf("Enter the name of the word you would like to remove.\n");
	    fscanf(stdin, "%s", deleteWord[l]);
	    destroyData(H, deleteWord[l]);
	    l++; 
	    flag = 0;
	}
	else if(choice[0] == '3'){
	    printf("Enter the name of the text file to search through.\n"); 
	    printf("No spaces and full file path\n");
	    fscanf(stdin, "%s", fileName);
	    searchFile = fopen(fileName, "r");
	    if(searchFile == NULL){
		printf("Error opening file\n");
	        return;
	    }
	    
	    flag = 0;
	    rewind(searchFile);
            while(!(feof(searchFile))){
		fscanf(searchFile, "%s", searchWords[m]);
	        flag2 = lookUpData(H, searchWords[m]);	
	        if(flag2 == 0){
		   wrongWords++;
		}
		else if(flag2 == 1){
		    rightWords++;
		}
	        else {
		    printf("Not a word\n");
		}
	        m++;
	    }
	    printf("Number of correct words <%d>\n", rightWords);
	    printf("Number of incorrect words <%d>\n", wrongWords);
	}
        else if(choice[0] == '4'){
	    for(i = 0; i < 26; i++){
	        printForward(H->table[i].l);
	    }
	    flag = 0;
	}
        else if(choice[0] == '5'){
	    printf("Good bye\n");
	    destroyTable(H);
	    if(searchFile != NULL){
	        fclose(searchFile);
	    }
	    return;
	}
	else {
	   
	        printf("error please enter 1, 2, 3, 4, or 5\n"); 
	        fscanf(stdin, "%s", choice);
	   
	    flag = 1;
	}
    }
}
