#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rule.h"
#include "BinSearchTreeAPI.h"
#include "ReadFile.h"
#include "simulation.h"

int main(int argc, char* argv[])
{

    FILE* FP = fopen(argv[1], "r");
    if(FP == NULL){
	printf("Error opening file\n");
	return 0;
    }
    Tree* theTree = createBinTree(compareRule, deleteRule, printRule);
    readFile(FP, theTree);
    return 0;
}
