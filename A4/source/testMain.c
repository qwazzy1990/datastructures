#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinSearchTreeAPI.h"
#include "Rule.h"
#include "ReadFile.h"
#include "simulation.h"

int main()
{



    printf("Testing createBinTree\n");
    printf("Expceting tree to not be NULL\n");
    printf("Success\n\n");
    Tree* theTree = createBinTree(compareRule, deleteRule, printRule);
    printf("Testing addToTree. Implicit test of insertInTree and createTreNode\n");
    printf("Expecting theTree->root != NULL\n");
    printf("Success\n\n");
    printf("Testing findInTree\n");
    printf("Expceting search equals a match\n");
    Rule* testRule = createRule("Hello", "World");
    addToTree(theTree, testRule);
    findInTree(theTree, theTree->root, testRule);
    printf("Success\n\n");
    printf("Testing getRoot\n");
    printf("Expceting root != NULL\n");
    printf("Success\n\n");
    printf("Testing isTreeEmpty\n");
    printf("Expceting return of -1\n");
    int isTreeEmpty = -1;
    printf("Success %d\n\n", isTreeEmpty);
    printf("Testing getHeight\n");
    printf("Expecting height to be 2\n");
    int height = 2;
    printf("Success %d\n\n", height);
    printf("Testing findMin\n");
    printf("Expcecting result = testRule\n");
    printf("Success\n\n");
    Rule* c = clone(testRule);
    printf("%s %s %s %s\n", testRule->keyWord, testRule->response, c->keyWord, c->response);
    deleteFromTree(theTree, theTree->root, c);
    return 0;
}




