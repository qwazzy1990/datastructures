
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SinglyLinkedListAPI.h"
#include "HashTableAPI.h"
#include "WordAPI.h"



HashTable* initializeHashTable(void(*dest)(void* d), int(*hash)(void* h))
{
    HashTable* h = (HashTable*)malloc(sizeof(HashTable));
    h->size = 26;
    h->table = createTable();
    h->destroy = dest;
    h->hashFunc = hash;
    return h;
}

HashNode* createTable()
{
   HashNode* t = (HashNode*)malloc(sizeof(HashNode)*26);
   int i = 0;
   for(i = 0; i < 26; i++){
	t[i].l = initializeList(&printString, &deleteString);
   }
   return t;
}

int hashFunction(void* stringToHash)
{
   
    char hash[10] = "\0";
    int i = 0;
    strcpy(hash, (char*)stringToHash);
    for(i = 0; i < strlen(hash); i++){
	if(hash[i] == '\n'){
	    hash[i] = '\0';
	}
    }
    if(!(isalpha(hash[0]) == 0)){

	if(!(isupper(hash[0]) == 0)){
	    return hash[0] - 65;
	}
	else {
	    return hash[0] - 97;
	}
    }
    else {
	return -1;
    }
}

void destroyTable(HashTable* H)
{
    int i = 0;
    for(i = 0; i < 26; i++){
        deleteList(H->table[i].l);
    }
    free(H->table);
    free(H);
}

void destroyData(HashTable* H, void* toBeDestroyed)
{
    int whereToDestroy = hashFunction(toBeDestroyed);
    if(whereToDestroy != -1){
	deleteNodeFromList(H->table[whereToDestroy].l, toBeDestroyed);
    }
    else {
	printf("Could not destroy input because it is not a word.\n");
    }
}

void insertDataInMap(HashTable* H, void* data)
{
    int whereToAdd = hashFunction(data);
    if(whereToAdd != -1){
	insertBack(H->table[whereToAdd].l, data); 
    }
    else {
	printf("That is not a word\n");
    }   
}

int lookUpData(HashTable* H, char key[])
{
    void* theKey = key;
    int hash = hashFunction(theKey);
    ListNode* findNode = H->table[hash].l->head;
    if(hash != -1){
   	 if(findNode == NULL){
		printf("%s does not exist\n", key);
		return 0;
   	 }
   	 while((findNode != NULL) && (!(strcmp((char*)findNode->data, key) == 0))){
		findNode = findNode->next;
   	 }
    	if(findNode == NULL){
		printf("%s does not exist\n", key);
		return 0;
    	}
    	else {
		printf("Found %s\n", key);
		return 1;
   	 }
    }
    else {
	return -1;
    }
}

void printTable(HashTable* H)
{
    int i = 0;
    for(i = 0; i < 26; i++){
	printForward(H->table[i].l);
    }
}

void test(List* L)
{
   printf("works\n");
   return;
}
