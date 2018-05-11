


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rule.h"
#include "simulation.h"
#include "BinSearchTreeAPI.h"
#include "ReadFile.h"


void removeHardReturn(char x[])
{
    int i = 0;
    for(i = 0; i < strlen(x); i++){
	if(x[i]=='\n'){
	    x[i] = '\0';
	}
    }
}

void readFile(FILE* FP, Tree* T)
{
      rewind(FP); 
      int k = 0;
      int flagResponse = 0;
      int flagKeyWord = 0;
      char isKeyWord[1000][1000];
      char isResponse[1000][1000];
      char buffer[1000]; 
      while(!feof(FP)){
          fgets(buffer, 1000, FP);
          if(buffer[0] != '\n'){
              removeHardReturn(buffer); 
              if(flagKeyWord == 0 && flagResponse == 0){
                  strncpy(isKeyWord[k], buffer, strlen(buffer));
  		  flagKeyWord = 1;
               }
               else{
                  strncpy(isResponse[k], buffer, strlen(buffer));
  		  flagResponse = 1;
              }
              if(flagResponse == 1 && flagKeyWord == 1){
                  addToTree(T, createRule(isKeyWord[k], isResponse[k]));
                  flagResponse = 0;
                  flagKeyWord = 0;
                  k++;
              }
          }
          else {
              removeHardReturn(buffer);
          }
          if(feof(FP)){
              break;
          }
      }
     runSim(T);
     fclose(FP);
}










