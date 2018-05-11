
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedListAPI.h"
#include "FileInputAPI.h"
#include "WordAPI.h"
#include "HashTableAPI.h"
#include "SimulationAPI.h"

#define MAX 1000

void removeHardReturn(char x[])
{
    int i = 0;
    for(i = 0; i < MAX; i++){
	if(x[i] == '\n'){
	   x[i] = '\0';
	   return;
	}
    }
    printf("File Corrupted\n");
}

int findWordsInFile(HashTable* H, char x[])
{
    int n = 0;
    int wordExists = 0;
    int wordDoesNotExist = 0;
    n = lookUpData(H, x);
    if(n == 0){
	 wordDoesNotExist +=1;
	 return n;
    }
    else {
	wordExists +=1;
	return n;
    }	
    
}

void addFile(HashTable* H, FILE* fp)
{
    rewind(fp);
    int i = 0;
    void* toAdd = NULL;
    char fileLine[1000][1000]; 
    while(!(feof(fp))){
	fscanf(fp, "%s", fileLine[i]);
	toAdd = fileLine[i];
	insertDataInMap(H, toAdd);
        i++;
    }

}








