#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "LinkedList.h"
#include "utilities.h"

bool debug1 = false;
bool debug2 = true;
bool debug3 = false;

int main(int argc, char* argv[])
{
    if(debug1){
        //do shit
        LinkedList newList = new_linkedlist(dummy_print, dummy_delete, dummy_compare);
        new_object(Int, a, 1);
        new_object(Int, b, 1);
        new_object(Int, c, 1);
        *a = 3;
        *b = 12;
        *c = 22;
        insert_back(newList, a);
        insert_back(newList, b);
        insert_back(newList, c);
        String printer = list_to_string(newList);
        printf("%s\n", printer);
        clear(printer);
        clear(a);
        clear(b);
        clear(c);
    }
    if(debug2){
        LinkedList newList = new_linkedlist(dummy_print, dummy_delete, dummy_compare);
        new_object(Int, a, 1);
        new_object(Int, b, 1);
        new_object(Int, c, 1);
        *a = 3;
        *b = 12;
        *c = 22;
        insert_back(newList, a);
        insert_front(newList, b);
        insert_sorted(newList, c);
        /*String printer = list_to_string(newList);
        printf("%s\n", printer);
        Int* arrayOfInts = list_to_array(newList);
        int i = 0;
        while(arrayOfInts[i] != NULL){
            int p = *(arrayOfInts[i]);
            printf("p = %d\n", p);
            i++;
        }
        clear(arrayOfInts);
        clear(printer);*/
        
        //destroy_object_list(newList, b);
        String printer = list_to_string(newList);
        printf("%s\n", printer);
        clear(printer);
        //clear(a);
        //clear(c);
        destroy_list(newList);

    }
    if(debug3){
        //do shit
    }
    return 0;
}