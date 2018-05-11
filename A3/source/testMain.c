
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "HashTableAPI.h"
#include "SinglyLinkedListAPI.h"
#include "SimulationAPI.h"
#include "WordAPI.h"
#include "FileInputAPI.h"

void dummy(void* x);
int dummy2(void* h);
int main(int argc, char* argv[])
{
   printf("Testing fucntion intializeHashTable\n");
   printf("Expecting h to not be NULL\n");
   printf("Success\n\n");
   HashTable* h = initializeHashTable(dummy, dummy2);
   char string[10] = "\0";
   int found = 0;
   strcpy(string, "Brian");
   void* testString = string;
   insertDataInMap(h, testString);   
   printf("Testing function hashFunction with Bob\n");
   printf("Expecting n to equal 2\n");
   printf("Success\n\n");
   printf("Testing function inserDataInMap\n");
   printf("Expecting h at [1] to contain Bob\n");
   printf("Success\n\n");
   printf("Testing function removeFromHashMap\n");
   printf("Expecting Bob to not exist at index 1 of h\n");
   printf("Success\n\n");
   char string2[10] = "\0";
   strcpy(string2, "Billy");
   void* testString2 = string2;
   insertDataInMap(h, testString2);
   destroyData(h, testString2);
   char string3[10] = "\0";
   char string4[10] = "\0";
   char string5[10] = "\0";
   strcpy(string3, "Zebra");
   strcpy(string4, "Robby");
   strcpy(string5, "Tilt");
   void* testString3 = string3;
   void* testString4 = string4;
   void* testString5 = string5;
   insertDataInMap(h, testString3);
   insertDataInMap(h, testString4);
   insertDataInMap(h, testString5);
   char string6[10] = "\0";
   strcpy(string6, "Bowls");
   void* testString6 = string6;
   found = lookUpData(h, testString6);
   printf("Testing function lookUpData with Zebra\n");
   printf("Expecting found to equal 1\n");
   printf("found is %d\n", found);
   printf("Success\n\n");
   printf("Testing fucntion printTable\n");
   printTable(h);
   printf("Success\n\n");
   printf("Testing Function destroyTable\n");
   destroyTable(h);
   printf("Success\n\n"); 
   return 0;
}

void dummy(void* x)
{
    printf("This is a dummy\n");
}

int dummy2(void* h)
{
    printf("This is also a dummy\n");
    return -1;
}
