
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "WordAPI.h"
#include "SinglyLinkedListAPI.h"

void printString(void* data)
{
    int index = hashFunction(data);
    int key = hashFunction(data);
    printf("<%d>: <%d>: <%s>\n",index, key, (char*)data);
}

void deleteString(void* data)
{
    free(data);
}

void test2(HashTable* H)
{
    return;
}
