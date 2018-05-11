
#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedListAPI.h"

struct hashNode{
   List* l;
   struct hashNode* next;
   char* key;
}; 
typedef struct hashNode HashNode;

struct hTable{
   size_t size;
   HashNode* table;
   void (*destroy)(void* toBeDestroyed); //use this to delete a string at a node in the
   int (*hashFunc)(void* toBeHashed);
   
}; 
typedef struct hTable HashTable;

HashTable* initializeHashTable(void(*dest)(void* d), int(*hash)(void* h));

/**
   wrap this function in toBeAdded
   wrap this function in toBeDeleted
   wrap this function in lookUpData
*/
int hashFunction(void* stringToHash);
/**
   creates the hashTable
*/
HashNode* createTable();
//wrapper function to call deleteList
//then delete the table
//then free the HashTable
//need to call it for each List*
void destroyTable(HashTable* H);
/**
   Use this as a wrapper to call deleteNodeFromList
*/
void destroyData(HashTable* H, void* toBeDestroyed);
/**
   wrapped inside
*/
int lookUpData(HashTable* H, char key[]);


/**
   call insertBack
*/
void insertDataInMap(HashTable* H, void* key);

void printTable(HashTable* H);

void test(List* L);
void destroyer(void* d);
int hasher(void* h);
#endif 
