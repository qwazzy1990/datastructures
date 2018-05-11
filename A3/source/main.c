
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WordAPI.h"
#include "SinglyLinkedListAPI.h"
#include "HashTableAPI.h"
#include "SimulationAPI.h"
#include "FileInputAPI.h"

void destroyer(void* d);
int hasher(void* h);
int main(int argc, char* argv[])
{
  FILE* FP = fopen(argv[1], "r");
  char line[1000][1000];
  int i = 0;
  void* x = NULL;
  if(FP != NULL){
    rewind(FP);
    HashTable* h = initializeHashTable(destroyer, hasher);
    while(!(feof(FP))){
	fscanf(FP, "%s", line[i]);
        x = line[i];
        insertDataInMap(h, x);
        i++;
    }     
    runSim(h);
  }
  else {
    printf("File Does Not Exist\n");
    return 0;
  }
  fclose(FP);
  return 0;

}

void destroyer(void* d){
    return;
}

int hasher(void* h){
    return -1;
}
