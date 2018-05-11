
#ifndef _FILE_INPUT_API_
#define _FILE_INPUT_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableAPI.h"

void removeHardReturn(char x[]);
//will need to call removeHardReturn
int findWordsInFile(HashTable* H, char x[]);
//will need to call removeHardReturn
void addFile(HashTable* H, FILE* fp);






#endif 
