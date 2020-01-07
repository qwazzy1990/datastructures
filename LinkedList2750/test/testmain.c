#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "Numbers.h"
#include "DynamicString.h"
#include "utilities.h"


bool DEBUG1 = true;
bool DEBUG2 = false;
bool DEBUG3 = false;
bool DEBUG4 = false;
bool DEBUG5 = false;
int main(int argc, char* argv[])
{
    Int a = new_int();
    Int b = new_int();
    Int c = new_int();
    if(DEBUG1)
    {
        List* l = initializeList(print_int, destroy_int, dummy_compare);
        a->add(a, 1, 1);
        b->add(b, 1, 12);
        c->add(c, 1, 2);

        insertBack(l, a);
        insertBack(l, b);
        insertBack(l, c);
        char* printer = toString(l);
        printf("%s\n", printer);
        free(printer);
        freeList(l);
        //DO SHIT
    }
    if(DEBUG2)
    {
        //DO SHIT
    }
    if(DEBUG3)
    {
        //DO SHIT
    }
    return 0;
}